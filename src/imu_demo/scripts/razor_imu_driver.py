#!/usr/bin/env python

import rospy
import serial
import math
from math import radians
import tf
from sensor_msgs.msg import Imu


if __name__ == '__main__':
    try:
        rospy.init_node('razor_imu_driver')

        # Frame ID params
        child_frame = rospy.get_param('~child_frame', default='imu')
        parent_frame = rospy.get_param('~parent_frame', default='map')

        # Constants
        gravity_accel = 9.80665
        deg_to_rad = math.pi / 180

        # IMU message publisher
        pub_imu = rospy.Publisher('imu', Imu, queue_size=1)

        while not rospy.is_shutdown():
            try:
                ser = serial.Serial('/dev/razor_imu', 115200, timeout=1)
                rospy.loginfo('Connected!')
                break
            except serial.serialutil.SerialException:
                rospy.logwarn('Failed to connect...')
                rospy.sleep(1)

        while not rospy.is_shutdown():
            try:
                if not ser.is_open:
                    try:
                        ser = serial.Serial('/dev/razor_imu', 115200, timeout=1)
                        rospy.loginfo('Connected!')
                    except serial.serialutil.SerialException:
                        rospy.logwarn('Failed to connect...')
                        rospy.sleep(1)
                        continue

                line = ser.readline()

                data_stamp = rospy.Time.now()

                ascii_data = line.split(',')
                ascii_data = [s.strip() for s in ascii_data]
            
                ascii_data[0] = ascii_data[0][7:]
                if len(ascii_data) != 9:
                    print len(ascii_data)
                    rospy.loginfo_throttle(0.5, 'waiting for stream')
                    continue

                quaternion = tf.transformations.quaternion_from_euler(radians(float(ascii_data[1])), -radians(float(ascii_data[2])), -radians(float(ascii_data[0])))
                #print ascii_data
                imu_msg = Imu()
                imu_msg.header.stamp = data_stamp
                imu_msg.header.frame_id = child_frame
                imu_msg.linear_acceleration.x = float(ascii_data[3]) * gravity_accel
                imu_msg.linear_acceleration.y = float(ascii_data[4]) * gravity_accel
                imu_msg.linear_acceleration.z = float(ascii_data[5]) * gravity_accel
                imu_msg.angular_velocity.x = float(ascii_data[6]) * deg_to_rad
                imu_msg.angular_velocity.y = float(ascii_data[7]) * deg_to_rad
                imu_msg.angular_velocity.z = float(ascii_data[8]) * deg_to_rad
                imu_msg.orientation.w = float(quaternion[3])
                imu_msg.orientation.x = float(quaternion[0])
                imu_msg.orientation.y = float(quaternion[1])
                imu_msg.orientation.z = float(quaternion[2])

                pub_imu.publish(imu_msg)
                #rospy.loginfo("Message sent")
            except serial.serialutil.SerialException:
                rospy.logwarn('Lost connection')
                ser.close()

            except ValueError:
                pass

    except rospy.ROSInterruptException:
        pass

    ser.close()
