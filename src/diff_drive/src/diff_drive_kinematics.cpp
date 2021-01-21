#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>
#include <ros/ros.h>

const double WHEEL_DISTANCE = 1;
const double WHEEL_RADIUS = 0.2;

ros::Publisher pub_left_wheel;
ros::Publisher pub_right_wheel;

void recvTwist(const geometry_msgs::TwistConstPtr& msg){
  double v = msg->linear.x;
  double psi_dot = msg->angular.z;

  std_msgs::Float64 left_wheel_speed;
  std_msgs::Float64 right_wheel_speed;

  left_wheel_speed.data = (1/WHEEL_RADIUS)*(v-WHEEL_DISTANCE*psi_dot/2);
  right_wheel_speed.data = (1/WHEEL_RADIUS)*(v+WHEEL_DISTANCE*psi_dot/2);
  
  pub_left_wheel.publish(left_wheel_speed);
  pub_right_wheel.publish(right_wheel_speed);
}

int main(int argc, char** argv){
  ros::init(argc,argv,"diff_drive_kinematics");
  ros::NodeHandle nh;

  pub_left_wheel = nh.advertise<std_msgs::Float64>("left_wheel_speed", 1);
  pub_right_wheel = nh.advertise<std_msgs::Float64>("right_wheel_speed", 1);
  
  ros::Subscriber sub_twist = nh.subscribe("cmd_vel", 1, recvTwist);
  ros::spin();
}