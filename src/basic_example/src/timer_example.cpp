#include <ros/ros.h>

void timerCallback(const ros::TimerEvent& event){
  ros::Duration time_since_last_real = event.current_real - event.last_real;
  ros::Duration time_since_last_expected = event.current_expected - event.last_expected;

  ROS_INFO("Last Real: %f,   Last Expecte: %f", time_since_last_real.toSec(), time_since_last_expected.toSec());

}

int main(int argc, char** argv){
  ros::init(argc,argv,"timer_example");
  ros::NodeHandle nh;

  ros::Timer timer = nh.createTimer(ros::Duration(1), timerCallback);

  ros::spin();
}