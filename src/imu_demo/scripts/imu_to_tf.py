#!/usr/bin/env python

import rospy
import tf
from sensor_msgs.msg import Imu
from nav_msgs.msg import Odometry


class ImuToTf:
    def __init__(self):
        rospy.init_node('imu_to_tf')

        self.child_frame = rospy.get_param('~child_frame', default='zed_center')
        self.parent_frame = rospy.get_param('~parent_frame', default='map')

        # IMU message subscriber
        rospy.Subscriber('zed/odom', Odometry, self.recv_imu)

        # TF broadcaster
        self.br = tf.TransformBroadcaster()

    def recv_imu(self, msg):
        self.br.sendTransform(translation=(msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z),
                              rotation=(msg.pose.pose.orientation.x, msg.pose.pose.orientation.y, msg.pose.pose.orientation.z, msg.pose.pose.orientation.w),
                              time=msg.header.stamp,
                              child=self.child_frame,
                              parent=self.parent_frame
                              )

if __name__ == '__main__':
    try:
        node_instance = ImuToTf()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
