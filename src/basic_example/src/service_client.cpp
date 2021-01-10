#include <ros/ros.h>
#include <basic_example/Adder.h>

int main(int argc, char** argv){
  ros::init(argc,argv,"service_client");
  ros::NodeHandle node;

  ros::ServiceClient srv = node.serviceClient<basic_example::Adder>("adder_service");

  basic_example::AdderRequest req;
  basic_example::AdderResponse res;

  req.value1 = 20;
  req.value2 = 40;

  srv.waitForExistence();
  
  bool status = srv.call(req,res);

  if(status){
    ROS_INFO("%f",res.result);
  } else {
    ROS_WARN("Service call failed");
  }

  return 0;
}