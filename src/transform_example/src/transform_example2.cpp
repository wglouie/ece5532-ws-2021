#include <ros/ros.h>
#include <eigen3/Eigen/Dense>

int main(int argc, char** argv){
  ros::init(argc,argv,"transform_example2");
  ros::NodeHandle nh;

  Eigen::Vector3d T_VG;
  Eigen::Matrix3d R_VG;

  R_VG << cos(3.14*2/3), -sin(3.14*2/3), 0, sin(3.14*2/3), cos(3.14*2/3), 0, 0, 0, 1;
  T_VG << 14,14,0;

  ROS_INFO_STREAM("\n" << R_VG);
  ROS_INFO_STREAM("\n" << T_VG);

  Eigen::Vector3d target_global;

  target_global << 5, 27 , 0;

  Eigen::Vector3d target_vehicle;

  target_vehicle = R_VG.transpose()*target_global - R_VG.transpose()*T_VG;
  
  ROS_INFO_STREAM("\n" << target_vehicle);
}