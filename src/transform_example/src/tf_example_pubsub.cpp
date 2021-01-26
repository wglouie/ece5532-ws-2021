#include <ros/ros.h>
#include <tf/tf.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>

tf::Transform transform;
ros::Publisher point_pub;
ros::Publisher transform_pub;

void ptcallback(const geometry_msgs::PointConstPtr& msg){
  tf::Vector3 target_global(msg->x, msg->y, msg->z);
  tf::Vector3 target_vehicle;

  target_vehicle = transform.inverse() * target_global;

  geometry_msgs::Point point_msg;
  point_msg.x = target_vehicle.getX();
  point_msg.y = target_vehicle.getY();
  point_msg.z = target_vehicle.getZ();

  point_pub.publish(point_msg);
}

void timerCallback(const ros::TimerEvent& event){
  geometry_msgs::Pose pose_msg;
  pose_msg.orientation.w = transform.getRotation().getW();
  pose_msg.orientation.x = transform.getRotation().getX();
  pose_msg.orientation.y = transform.getRotation().getY();
  pose_msg.orientation.z = transform.getRotation().getZ();

  pose_msg.position.x = transform.getOrigin().getX();
  pose_msg.position.y = transform.getOrigin().getY();
  pose_msg.position.z = transform.getOrigin().getZ();
  
  transform_pub.publish(pose_msg); 
}

int main(int argc, char** argv){
  ros::init(argc, argv, "tf_example_pubsub");
  ros::NodeHandle nh;
  
  ros::Timer timer = nh.createTimer(ros::Duration(1.0), timerCallback);
  transform_pub = nh.advertise<geometry_msgs::Pose>("transform_out",1);

  ros::Subscriber point_sub = nh.subscribe("point_in",1,ptcallback);
  point_pub = nh.advertise<geometry_msgs::Point>("point_out",1);

  tf::Vector3 T_GV(14,14,0);
  tf::Quaternion R_GV(tf::createQuaternionFromYaw(M_PI*120/180));

  transform.setRotation(R_GV);
  transform.setOrigin(T_GV);

  ros::spin();
}