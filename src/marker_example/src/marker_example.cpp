#include <ros/ros.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf/tf.h>

ros::Publisher pub_markers;

void timerCallback(const ros::TimerEvent& event){
  visualization_msgs::MarkerArray marker_array_msg;

  marker_array_msg.markers.resize(2);

  visualization_msgs::Marker marker;

  marker.header.frame_id = "map";
  marker.header.stamp = event.current_real;
  marker.type = visualization_msgs::Marker::ARROW;
  marker.action = visualization_msgs::Marker::ADD;

  marker.scale.x = 1.0;
  marker.scale.y = 0.3;
  marker.scale.z = 0.3;

  marker.color.r = 1.0;
  marker.color.g = 0.0;
  marker.color.b = 0.0;
  marker.color.a = 1.0;

  marker.pose.position.x = 2.0;
  marker.pose.position.y = 0.0;
  marker.pose.position.z = 0.0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 0.0;
  marker.id = 0;

  marker_array_msg.markers[0] = marker;

  marker.header.frame_id = "frame1";
  marker.header.stamp = event.current_real;
  marker.type = visualization_msgs::Marker::CUBE;
  marker.action = visualization_msgs::Marker::ADD;

  marker.scale.x = 0.3;
  marker.scale.y = 0.3;
  marker.scale.z = 0.3;

  marker.color.r = 0.0;
  marker.color.g = 0.0;
  marker.color.b = 1.0;
  marker.color.a = 1.0;

  marker.pose.position.x = 2.0;
  marker.pose.position.y = 0.0;
  marker.pose.position.z = 0.0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 0.0;
  marker.id = 1;

  marker_array_msg.markers[1] = marker;

  if(marker_array_msg.markers.size() != 0){
    pub_markers.publish(marker_array_msg);
    ROS_INFO("Marker array is being published");
  } else{
    ROS_WARN("Marker array is empty");
  }
}

int main(int argc, char** argv){
  ros::init(argc,argv,"marker_example");
  ros::NodeHandle nh;

  pub_markers = nh.advertise<visualization_msgs::MarkerArray>("markers",1);
  ros::Timer marker_timer = nh.createTimer(ros::Duration(0.05),timerCallback);

  ros::spin();
}