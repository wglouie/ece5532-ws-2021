#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <nav_msgs/Path.h>
#include <ugv_course_libs/gps_conv.h>

UTMCoords ref_coords;
tf::Vector3 relative_position;
nav_msgs::Path gps_path;
ros::Publisher path_pub;

void timerCallback(const ros::TimerEvent& event){
  geometry_msgs::PoseStamped current_pose;
  current_pose.pose.position.x = relative_position.x();
  current_pose.pose.position.y = relative_position.y();
  
  gps_path.poses.push_back(current_pose);
  gps_path.header.frame_id="world";
  gps_path.header.stamp = event.current_real;
  path_pub.publish(gps_path);
}

void recvFix(const sensor_msgs::NavSatFixConstPtr& msg){
  UTMCoords current_coords(*msg);

  relative_position = current_coords - ref_coords;

  ROS_INFO("Current UTM: (%f, %f)", current_coords.getX(), current_coords.getY());
  ROS_INFO("Relative Position: (%f, %f)", relative_position.x(), relative_position.y());
  
}

int main(int argc, char** argv){
  ros::init(argc,argv,"gps_example");
  ros::NodeHandle nh;
  ros::Subscriber gps_sub = nh.subscribe("/audibot/gps/fix",1,recvFix);
  ros::Timer timer = nh.createTimer(ros::Duration(0.5), timerCallback);
  path_pub = nh.advertise<nav_msgs::Path>("gps_path",1);

  double ref_lat;
  double ref_lon;

  nh.getParam("/audibot/gps/ref_lat",ref_lat);
  nh.getParam("/audibot/gps/ref_lon",ref_lon);
  
  LatLon ref_coords_lat_lon(ref_lat, ref_lon, 0);
  ref_coords = UTMCoords(ref_coords_lat_lon);

  double central_meridian = ref_coords.getCentralMeridian();

  ROS_INFO("Central Meridian of the Reference Cooridinate: %f", central_meridian);
  
  ros::spin();
}