// Include guard to prevent multiple declarations
#ifndef NODECLASS_H
#define NODECLASS_H

// ROS header
#include <ros/ros.h>

// Namespace matches ROS package name
namespace package_name{

class NodeClass
{
public:
  NodeClass(ros::NodeHandle n, ros::NodeHandle pn);
  
};

}

#endif // NODECLASS_H

