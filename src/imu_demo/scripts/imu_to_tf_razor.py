#!/usr/bin/env python

import rospy
import tf
from sensor_msgs.msg import Imu


class ImuToTf:
    def __init__(self):
        rospy.init_node('imu_to_tf')

        self.child_frame = rospy.get_param('~child_frame', default='imu')
        self.parent_frame = rospy.get_param('~parent_frame', default='map')

        # IMU message subscriber
        rospy.Subscriber('imu', Imu, self.recv_imu)

        # TF broadcaster
        self.br = tf.TransformBroadcaster()

    def recv_imu(self, msg):
        self.br.sendTransform(translation=(0, 0, 0),
                              rotation=(msg.orientation.x, msg.orientation.y, msg.orientation.z, msg.orientation.w),
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
