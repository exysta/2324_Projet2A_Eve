#!/usr/bin/env python3

import rclpy
import time
import math
from rclpy.node import Node
from random import randint
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Twist

class MinimalPublisher(Node):
      
     def __init__(self):
         super().__init__('joint_publisher')
         self.publisher_ = self.create_publisher(JointState,'joint_states', 10)
         self.sub = self.create_subscription(Twist,'xyz_coord',self.sub_callback,10) 
         self.longueur_robot = [0.2,0.3,0.25,0.25]
         
     def sub_callback(self,data):
         # get x y z value
         x = data.linear.x
         y = data.linear.y
         z = data.linear.z
         pos = self.get_q_value(x,y,z)
         # create JointState msg
         msg = JointState()
         msg.position = pos 
         msg.header.stamp.sec = int(time.time())
         msg.header.stamp.nanosec = int((10**9) * (time.time()-int(time.time())))
         msg.name = ["pivot_01","pivot_12","pivot_23","pivot_34","pivot_45","pivot_56"]
         msg.velocity = [0.5,0.5,0.5,0.5,0.5,0.5]
         msg.effort = []
         self.publisher_.publish(msg)
         
     def get_q_value(self,x,y,z):
         l0,l1,l2,l3 = self.longueur_robot[0],self.longueur_robot[1],self.longueur_robot[2],self.longueur_robot[3]
         if math.sqrt(x**2+y**2) > l1 + l2 + l3:
              x = l1 + l2 + l3
              y = 0
         if z > l0+l1+l2+l3:
              z = l0+l1+l2+l3
         pos = []
         q1 = math.atan2(-1*y,-1*x)
         N_q2 = (z-l0-l1)**2+(x*math.cos(q1)+y*math.sin(q1))**2-l2**2-l3**2
         D_q2 = 2*l2*l3
         q2_1 = math.sqrt(1-((N_q2)/(D_q2))**2)
         q2_2 = N_q2/D_q2
         q2 = math.atan2(q2_1,q2_2)
         N1_q3 = (l2+l3*math.cos(q2))*(x*math.cos(q1)+y*math.sin(q1))-l3*math.sin(q2)*(z-l0-l1)
         N2_q3 = (l2+l3*math.cos(q2))*(z-l0-l1)+l3*math.sin(q2)*(x*math.cos(q1)+y*math.sin(q1))
         D_q3 = (l2 + l3*math.cos(q2))**2 + (l3*math.sin(q2))**2
         q3 = math.atan2(N1_q3/D_q3,N2_q3/D_q3) - (math.pi / 2)
         q4,q5,q6 = 0.0,0.0,0.0
         return [q1,q2,q3,q4,q5,q6]
          
 
def main(args=None):
     rclpy.init(args=args)
 
     minimal_publisher = MinimalPublisher()
 
     rclpy.spin(minimal_publisher)
 
     # Destroy the node explicitly
     # (optional - otherwise it will be done automatically
     # when the garbage collector destroys the node object)
     minimal_publisher.destroy_node()
     rclpy.shutdown()
 
 
if __name__ == '__main__':
     main()
