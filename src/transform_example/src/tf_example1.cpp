#include <ros/ros.h>
#include <tf/tf.h>

int main(int argc, char** argv){
  ros::init(argc,argv,"tf_example1");
  ros::NodeHandle nh;

  tf::Vector3 T_GV(10,3,0);
  tf::Quaternion R_GV(tf::createQuaternionFromYaw(M_PI*120/180));

  tf::Transform transform;

  transform.setRotation(R_GV);
  transform.setOrigin(T_GV);

  tf::Vector3 target_global;
  tf::Vector3 target_vehicle(25,0,0);

  target_global = transform*target_vehicle;

  ROS_INFO("Global target position: %f, %f, %f", target_global.getX(), target_global.getY(), target_global.getZ());
  


}