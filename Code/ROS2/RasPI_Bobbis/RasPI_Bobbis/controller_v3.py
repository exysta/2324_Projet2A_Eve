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
         self.longueur_robot = [0.132,0.175,0.278,0.514]
         # Il faut peut être modifier ces valeur de longueurs avec le robot
         # Ou sinon l'echelle des x,y,z à entrer sera différente
         self.q_values = [0.0,0.0,0.0,0.0,0.0,0.0]
         self.create_pub_msg(self.q_values)
         
     def sub_callback(self,data):
         # get x y z value
         x = data.linear.x
         z = data.linear.z
         y = data.linear.y
         pos = self.get_q_value(x,y,z)
         self.create_pub_msg(pos)
         
     def create_pub_msg(self,pos): 
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
         pos = []
         try:
             q1 = math.atan2(-1*x,y)
             if q1 > math.pi:
                 q1 -= 2*math.pi
             elif q1 < -1*math.pi:
                 q1 += 2*math.pi
             A = y*math.cos(q1)-x*math.sin(q1)
             B = -1*z+l0+l1
             D_q2 = (2*l2*A)**2 + (2*l2*B)**2
             part_1_N_q2 = l3*l3-l2*l2-B*B-A*A
             part_2_N_q2 = math.sqrt(D_q2-part_1_N_q2**2)
             liste_N = []
             N1_q2 = -1*2*l2*A*part_1_N_q2 + 2*l2*B*part_2_N_q2
             N2_q2 = 2*l2*B*part_1_N_q2 + 2*l2*A*part_2_N_q2
             liste_N.append((N1_q2,N2_q2))
             N1_q2 = -1*2*l2*A*part_1_N_q2 - 2*l2*B*part_2_N_q2
             N2_q2 = 2*l2*B*part_1_N_q2 - 2*l2*A*part_2_N_q2
             liste_N.append((N1_q2,N2_q2))
             liste_erreur = []
             liste_q2_q3 = []
             for i in liste_N:
                 q2 = math.atan2(i[0]/D_q2,i[1]/D_q2)
                 if q2 > math.pi:
                     q2 -= 2*math.pi
                 elif q2 < -1*math.pi:
                     q2 += 2*math.pi
                 Z1 = -1*B*math.cos(q2)+A*math.sin(q2)-l2
                 Z2 = B*math.sin(q2)+A*math.cos(q2)
                 q3 = math.atan2((Z2)/(l3*l3),(Z1)/(l3*l3))
                 if q3 > math.pi:
                     q3 -= 2*math.pi
                 elif q3 < -1*math.pi:
                     q3 += 2*math.pi
                 liste_q2_q3.append((q2,q3))
                 x_theo = (l2*math.cos(q1)*math.sin(q2)) + (l3*math.cos(q1)*math.cos(q2+q3))
                 z_theo = (l2*math.sin(q1)*math.sin(q2)) + (l3*math.sin(q1)*math.cos(q2+q3))
                 y_theo = l0+l1+(l2*math.cos(q2))-(l3*math.sin(q2+q3))
                 x_theo = x
                 z_theo = z
                 y_theo = y
                 if x != 0:
                     err_x = (x-x_theo)/x
                 else:
                     err_x = x-x_theo
                 if y != 0:
                     err_y = (y-y_theo)/y
                 else:
                     err_y = y-y_theo
                 if z != 0:
                     err_z = (z-z_theo)/z
                 else:
                     err_z = z-z_theo
                 err = math.sqrt(err_x**2+err_y**2+err_z**2)
                 liste_erreur.append(err)
             err_min = min(liste_erreur)
             idx_err_min = liste_erreur.index(err_min)
             q2 = liste_q2_q3[idx_err_min][0]
             q3 = liste_q2_q3[idx_err_min][1]            
         except:
             q1,q2,q3 = 0.0,0.0,(math.pi/2)
         q4,q5,q6 = 0.0,(math.pi/2),0.0
         return [q1,q2,q3,q4,q5,q6] # Renvoie les angles de chaque moteur en radian

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
