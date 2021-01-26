#include <ros/ros.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>

#include <dynamic_reconfigure/server.h>
#include <quat_demo/QuatDemoConfig.h>

using namespace visualization_msgs;

ros::Publisher pub_markers;
visualization_msgs::Marker marker_msg;
tf::StampedTransform transform;

double truncDec(double val, int dec_places)
{
  double factor = 1.0;
  for (int i=0; i<dec_places; i++,factor*=10);

  return floor(factor * val) / factor;
}

void reconfig(quat_demo::QuatDemoConfig& config, uint32_t level)
{
  tf::Vector3 vect(config.a_x, config.a_y, config.a_z);

  if (vect.length2() == 0){
    config.a_x = 0.0;
    config.a_y = 0.0;
    config.a_z = 1.0;
  }else{
    vect.normalize();
    config.a_x = truncDec(vect.x(), 2);
    config.a_y = truncDec(vect.y(), 2);
    config.a_z = truncDec(vect.z(), 2);
  }

  double w = cos(0.5 * config.beta);
  double x = config.a_x * sin(0.5 * config.beta);
  double y = config.a_y * sin(0.5 * config.beta);
  double z = config.a_z * sin(0.5 * config.beta);
  transform.setRotation(tf::Quaternion(x, y, z, w));

  std::stringstream ss;
  ss << "w: " << truncDec(w, 3) << ", x: " << truncDec(x, 3) << ", y: " << truncDec(y, 3) << ", z: " << truncDec(z, 3);
  ROS_INFO("%s", ss.str().c_str());

  marker_msg.points[1].x = config.a_x;
  marker_msg.points[1].y = config.a_y;
  marker_msg.points[1].z = config.a_z;
}

void timerCallback(const ros::TimerEvent& event)
{
  static tf::TransformBroadcaster br;

  transform.frame_id_ = "map";
  transform.child_frame_id_ = "quat";
  transform.stamp_ = event.current_real;
  br.sendTransform(transform);

  marker_msg.header.stamp = event.current_real;
  pub_markers.publish(marker_msg);
}

void initMarkers()
{
  marker_msg.header.frame_id = "map";
  marker_msg.action = Marker::ADD;
  marker_msg.type = Marker::ARROW;

  marker_msg.color.a = 0.7;
  marker_msg.color.r = 1.0;
  marker_msg.color.g = 1.0;
  marker_msg.color.b = 1.0;

  marker_msg.scale.x = 0.1;
  marker_msg.scale.y = 0.2;
  marker_msg.scale.z = 0.25;
  marker_msg.points.resize(2);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "quat_demo");
  ros::NodeHandle n;

  initMarkers();

  // Topics and timers
  pub_markers = n.advertise<Marker>("/axis", 1);
  ros::Timer timer = n.createTimer(ros::Duration(0.02), timerCallback);

  // Dynamic reconfigure
  dynamic_reconfigure::Server<quat_demo::QuatDemoConfig> srv;
  srv.setCallback(boost::bind(reconfig, _1, _2));

  ros::spin();
}
