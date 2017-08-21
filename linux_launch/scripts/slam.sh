#!/bin/bash
source /opt/ros/kinetic/setup.bash
source /home/vincent/Project/path_planning/devel/setup.bash

export ROS_MASTER_URI=http://127.0.0.1:11311/
export ROS_IP=127.0.0.1

rosrun monitor slam
