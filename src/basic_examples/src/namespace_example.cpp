#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "namespace_example");
  ros::NodeHandle global_nh;
  ros::NodeHandle private_nh("~");

  ros::Publisher pub_global = global_nh.advertise<std_msgs::Float64>("global_topic",1);
  ros::Publisher pub_private = private_nh.advertise<std_msgs::Float64>("private_topic",1);
 

  ros::spin();
}