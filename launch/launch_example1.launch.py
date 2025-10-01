from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='kar_onb_gabor',
            executable='generalas',
        ),

        Node(
            package='kar_onb_gabor',
            executable='eredmeny',
        ),
    ])