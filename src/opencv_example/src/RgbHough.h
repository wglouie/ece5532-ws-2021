#ifndef RGBHOUGH_H
#define RGBHOUGH_H

#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>

// Dynamic reconfigure
#include <dynamic_reconfigure/server.h>
#include <opencv_example/RgbHoughConfig.h>

namespace opencv_example{

class RgbHough
{
public:
RgbHough(ros::NodeHandle n, ros::NodeHandle pn);

private:
  void reconfig(opencv_example::RgbHoughConfig& config, uint32_t level);
  void recvImage(const sensor_msgs::ImageConstPtr& msg);

  ros::Subscriber sub_image_;
  
  dynamic_reconfigure::Server<RgbHoughConfig> srv_;
  RgbHoughConfig cfg_;

};

}

#endif // RGBHOUGH_H
