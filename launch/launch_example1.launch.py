from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='karacsonygabor_package',
            executable='generalas',
        ),

        Node(
            package='karacsonygabor_package',
            executable='eredmeny',
        ),
    ])