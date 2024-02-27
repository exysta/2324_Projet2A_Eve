import rclpy
import RPi.GPIO as GPIO
import serial
from rclpy.node import Node
from sensor_msgs.msg import JointState
import numpy as np

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(3,GPIO.OUT) # 23 - 3
GPIO.setup(13,GPIO.IN) # 24 - 13

class UART_Publisher(Node):

    def __init__(self):
        super().__init__("Uart_publisher")
        self.sub = self.create_subscription(JointState,"joint_states",self.sub_clbck,10)
        self.q_values = [0,0,0,0,0,0]
        self.serial_port = serial.Serial("/dev/ttyAMA0")
        self.serial_port.baudrate = 9600
        self.serial_port.parity = serial.PARITY_NONE
        self.serial_port.stopbits = serial.STOPBITS_ONE
        self.serial_port.bytesize = serial.EIGHTBITS
        self.serial_port.timeout = 1
        
    def sub_clbck(self,data):
        for i in range(len(self.q_values)):
            self.q_values[i] = int(100*data.velocity[i])
        ''' transmission par UART '''
        ''' A refaire car ça marche pas :/ '''
        begin_trame = np.uint16(65535)
        end_trame = np.uint16(65535)
        data1,data2,data3,data4,data5,data6 = np.uint8(self.q_values)
        buffer = [(begin_trame>>8)&0xFF, (begin_trame&0xFF),data1,data2,data3,data4,data5,data6,(fin_trame>>8)&0xFF, (fin_trame&0xFF)]
        self.serial_port.write(bytearray(buffer))
        self.serial_port.flush()


def main(args=None):
     rclpy.init(args=args)
     pub = UART_Publisher()
     rclpy.spin(pub)
     pub.destroy_node()
     rclpy.shutdown()
 
 
if __name__ == '__main__':
     main()
