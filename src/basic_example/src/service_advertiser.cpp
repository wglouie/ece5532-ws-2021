#include <ros/ros.h>
#include <basic_example/Adder.h>

bool serviceCallback(basic_example::Adder::Request& req, basic_example::Adder::Response& res){
  res.result = req.value1 + req.value2;
  return true;
}

int main(int argc, char** argv){
  ros::init(argc,argv,"service_advertiser");
  ros::NodeHandle node;

  ros::ServiceServer srv = node.advertiseService("adder_service",serviceCallback);
  ros::spin();
}