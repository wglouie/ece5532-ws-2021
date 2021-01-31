#include <ros/ros.h>
#include <basic_examples/Adder.h>

bool serviceCallback(basic_examples::Adder::Request& req, basic_examples::Adder::Response& res){
  res.result = req.value1 + req.value2;
  return true;
}

int main(int argc, char** argv){
  ros::init(argc,argv,"service_advertiser");
  ros::NodeHandle node;

  ros::ServiceServer srv = node.advertiseService("adder_service",serviceCallback);
  ros::spin();
}