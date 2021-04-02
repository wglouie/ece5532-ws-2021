#include <ros/ros.h>
#include "RgbHough.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "rgb_hough_node");
  ros::NodeHandle n;
  ros::NodeHandle pn("~");
  
  opencv_example::RgbHough node(n, pn);

  ros::spin();
}
