#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char** argv){
  ros::init(argc,argv,"topic_publisher");
  ros::NodeHandle node;
  ros::spin();
}