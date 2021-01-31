#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <tf_example/TFExampleConfig.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>

tf_example::TFExampleConfig config;

void reconfig(tf_example::TFExampleConfig& cfg, const uint32_t& level){
  config = cfg;
}

void timerCallback(const ros::TimerEvent& event){
  static tf::TransformBroadcaster broadcaster;

  tf::StampedTransform transform;
  transform.frame_id_ = "map";
  transform.child_frame_id_ = "frame1";
  transform.stamp_ = event.current_real;
  transform.setOrigin(tf::Vector3(config.x,config.y, 0));
  transform.setRotation(tf::createQuaternionFromYaw(config.yaw));

  broadcaster.sendTransform(transform);
}

int main(int argc, char** argv){
  ros::init(argc,argv,"tf_example");
  ros::NodeHandle nh;

  dynamic_reconfigure::Server<tf_example::TFExampleConfig> srv;
  srv.setCallback(boost::bind(reconfig,_1,_2));

  ros::Timer timer = nh.createTimer(ros::Duration(0.2),timerCallback);

  ros::spin();
}