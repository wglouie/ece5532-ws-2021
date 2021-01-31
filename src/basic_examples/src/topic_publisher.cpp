#include <ros/ros.h>
#include <std_msgs/String.h>

ros::Publisher pub_string;

void recvString(const std_msgs::StringConstPtr& msg){
  std_msgs::String new_string;
  new_string.data = msg->data + "_123";
  pub_string.publish(new_string);
}

int main(int argc, char** argv){
  ros::init(argc,argv,"topic_publisher");
  ros::NodeHandle node;

  ros::Subscriber sub_string = node.subscribe("/topic_in", 1, recvString);
  pub_string = node.advertise<std_msgs::String>("/topic_out",1);

  ros::spin();
}