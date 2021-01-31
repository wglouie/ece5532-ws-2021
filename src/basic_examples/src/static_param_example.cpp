#include <ros/ros.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "static_param_example");
  ros::NodeHandle global_nh;
  ros::NodeHandle private_nh("~");

  double p1;
  double p2;
  double p3;

  global_nh.param("p1",p1,1.0);
  bool param_set = global_nh.getParam("p2", p2);

  private_nh.param("p3",p3,5.0);

  ROS_INFO("The value of p1 is: %f", p1);
  
  if(param_set){
    ROS_INFO("The value of p2 is: %f", p2);
  } else {
    ROS_WARN("The parameter p2 was not set correctly. Your node may not run correctl");
  }

  ROS_INFO("The value of p3 is %f",p3);

  ros::spin();
}