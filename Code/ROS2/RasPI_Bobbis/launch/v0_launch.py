import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    
    urdf_file_name = 'URDF_Assemblage.xacro'
    urdf = os.path.join(get_package_share_directory('RasPI_Bobbis'),
                        urdf_file_name)
    with open(urdf, 'r') as file:
        robot_desc = file.read()
        
    return LaunchDescription([
        Node(
            package='RasPI_Bobbis',
            executable='controller_v3',
            name='joint_publisher',
            output='screen',
            remappings=[("/controller_v3/joint_publisher","/joint_states"),]
            ),
        Node(
            package='RasPI_Bobbis',
            executable="xyz_pub",
            name='xyz_pub',
            output='screen'
            ),
        Node(
            package='RasPI_Bobbis',
            executable="uart_transmit",
            name="uart_transmit",
            output='screen'
            )

   ])
