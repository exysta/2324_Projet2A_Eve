import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


class XYZPublisher(Node):
      
     def __init__(self):
         super().__init__('xyz_publisher')
         self.publisher_ = self.create_publisher(Twist,'xyz_coord', 10)
         timer_period = 2  # seconds
         self.timer = self.create_timer(timer_period,self.timer_callback)
         self.changed_id = 0
         
     def timer_callback(self):
         msg = Twist()
         ''' à modifier '''
         ''' Gere les inputs de x,y,z
         remplacer les constantes x,y,z par une acquisition de la commande
         et changed_id doit être mis à 1 quand on reçoit des nouvelles val
         '''
         x = 0.2
         y = 0.3
         z = 0.5
         self.changed_id = 1
         ''' /à modifier '''
         if self.changed_id:
              self.changed_id = 0
              msg.linear.x = x
              msg.linear.y = y
              msg.linear.z = z
              self.publisher_.publish(msg)
       
 
 
def main(args=None):
     rclpy.init(args=args)
     xyz_publisher = XYZPublisher()
     rclpy.spin(xyz_publisher)
 
     # Destroy the node explicitly
     # (optional - otherwise it will be done automatically
     # when the garbage collector destroys the node object)
     
     
     xyz_publisher.destroy_node()
     rclpy.shutdown()
 
 
if __name__ == '__main__':
     main()
