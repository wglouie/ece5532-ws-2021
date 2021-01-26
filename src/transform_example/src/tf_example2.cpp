#include <ros/ros.h>
#include <tf/tf.h>

int main(int argc, char** argv){
  ros::init(argc,argv, "tf_example2");
  ros::NodeHandle nh;

  tf::Vector3 T_GV(14,14,0);
  tf::Quaternion R_GV(tf::createQuaternionFromYaw(M_PI*120/180));

  tf::Transform transform;

  transform.setRotation(R_GV);
  transform.setOrigin(T_GV);

  tf::Vector3 target_global(5,27,0);
  tf::Vector3 target_vehicle;

  target_vehicle = transform.inverse()*target_global;

  ROS_INFO("Target vehicle: %f, %f, %f", target_vehicle.getX(), target_vehicle.getY(), target_vehicle.getZ());
  
}