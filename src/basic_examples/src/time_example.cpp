#include <ros/ros.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "time_example");
  ros::NodeHandle nh;

  ros::Time current_time = ros::Time::now();
  ros::Duration one_minute(60);
  ros::Time sixty_seconds_later = current_time + one_minute;

  double current_time_value = current_time.toSec();

  ROS_INFO("%f", current_time_value);
  ROS_INFO("now: %f, sixty seconds later: %f", current_time.toSec(), sixty_seconds_later.toSec());
  ROS_INFO("Difference in time: %f", (sixty_seconds_later - current_time).toSec());
  ros::spin();
}