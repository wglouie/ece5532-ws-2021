#include <ros/ros.h>
#include <eigen3/Eigen/Dense>

int main(int argc, char** argv){
  ros::init(argc,argv,"transform_example1");
  ros::NodeHandle nh;

  Eigen::Vector3d T_VG;
  Eigen::Matrix3d R_VG;

  R_VG << cos(3.14*2/3), -sin(3.14*2/3), 0, sin(3.14*2/3), cos(3.14*2/3), 0, 0, 0, 1;
  T_VG << 10,3,0;

  ROS_INFO_STREAM("\n" << R_VG);
  ROS_INFO_STREAM("\n" << T_VG);

  Eigen::Vector3d target_vehicle;

  target_vehicle << 25, 0 , 0;

  Eigen::Vector3d target_global;

  target_global = R_VG * target_vehicle + T_VG;

  ROS_INFO_STREAM("\n" << target_global);
}