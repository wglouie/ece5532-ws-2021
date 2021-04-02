#include "RgbHough.h"

namespace opencv_example {

RgbHough::RgbHough(ros::NodeHandle n, ros::NodeHandle pn)
{

  sub_image_ = n.subscribe("image_in", 1, &RgbHough::recvImage, this);

  srv_.setCallback(boost::bind(&RgbHough::reconfig, this, _1, _2));

  cv::namedWindow("Raw Image", CV_WINDOW_AUTOSIZE);
  cv::namedWindow("Blue Image", CV_WINDOW_AUTOSIZE);
  cv::namedWindow("Thres Image", CV_WINDOW_AUTOSIZE);
  cv::namedWindow("Erode Image", CV_WINDOW_AUTOSIZE);
  cv::namedWindow("Dilate Image", CV_WINDOW_AUTOSIZE);
  cv::namedWindow("Lines Image", CV_WINDOW_AUTOSIZE);
}

void RgbHough::recvImage(const sensor_msgs::ImageConstPtr& msg)
{
  cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  cv::Mat raw_img = cv_ptr->image;

  cv::imshow("Raw Image", raw_img);
  cv::waitKey(1);

  std::vector<cv::Mat> split_images;
  cv::split(raw_img, split_images);

  cv::Mat blue_image = split_images[0];
//   cv::Mat green_image = split_images[1];
//   cv::Mat red_image = split_images[2];

  cv::imshow("Blue Image", blue_image);
  cv::waitKey(1);

  cv::Mat thres_img;
  cv::threshold(blue_image, thres_img, cfg_.blue_thres, 255, cv::THRESH_BINARY);

  cv::imshow("Thres Image", thres_img);
  cv::waitKey(1);

  cv::Mat erode_img;
  cv::erode(thres_img, erode_img, cv::Mat::ones(cfg_.erode_size, cfg_.erode_size, CV_8U));

  cv::imshow("Erode Image", erode_img);
  cv::waitKey(1);

  cv::Mat dilate_img;
  cv::dilate(erode_img, dilate_img, cv::Mat::ones(cfg_.dilate_size, cfg_.dilate_size, CV_8U));

  cv::imshow("Dilate Image", dilate_img);
  cv::waitKey(1);

  std::vector<cv::Vec4i> line_segments;
  cv::HoughLinesP(dilate_img, line_segments, cfg_.hough_rho_res, cfg_.hough_theta_res,
		  cfg_.hough_threshold, cfg_.hough_min_length, cfg_.hough_max_gap);

  for (int i=0; i<line_segments.size(); i++){
    cv::line(raw_img, cv::Point(line_segments[i][0], line_segments[i][1]),
	    cv::Point(line_segments[i][2], line_segments[i][3]), cv::Scalar(0, 0, 255));
  }

  cv::imshow("Lines Image", raw_img);
  cv::waitKey(1);

}

void RgbHough::reconfig(opencv_example::RgbHoughConfig& config, uint32_t level)
{

  if ((config.erode_size % 2) == 0) {
    config.erode_size--;
  }

  if ((config.dilate_size % 2) == 0) {
    config.dilate_size--;
  }

  cfg_ = config;
}

}
