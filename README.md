# Disclaimer
This project isn't complete, and also not general enough. Please take care of this.

# Package Explaination
- **simple_ros_control**: 
Just for metapackage informations.
- **simple_ros_control_main**:
The main package for ROS control, including hardware_interface, transmission_interface..., etc. This package is responsible for registering joints to ROS controller manager and updating motor commands. Your robots will share this package.
- **communication_interface**(\*1):
Implement your communication functions here to fit your robots. Notice that all the functions defined here, such as **init()** and **update_pp()**, will be called by **simple_ros_control_main** package. So please don't add or delete functions. Just implement the what the function wants. 
- **simple_robot_description**:
Put your urdf here, with their names "simple_diff_robot.xacro"(if a differential drive platform) or "simple_robot.urdf"(if a robot arm). I will change these names to make more sense in the future.
- **simple_robot_moveit_config**:
If you use a robot arm, please put your moveit config here. Please DON'T change the package name (namely, **simple_robot_moveit_config**) because the package will be called by **simple_ros_control_main**.
- **simple_robot_config**: 
There are two .yaml here now: **arm_ros_control.yaml** and **diff_ros_control.yaml**. Modify the content, including degree of freedom, gear ratios, update frequency..., etc. to fit your robots.

\*1:This is beacuse I want to make **simple_ros_control_main** independent. More clearly, whenever **simple_ros_control_main** updates, different robots don't have to modify the motor communication functions. If you have better ideas, please tell me. Thanks!


# Demo
Edit the config file:
```
rosed simple_robot_config arm_ros_control.yaml
```
Change the **control_type** to **fake**, namely:
```
control_type: fake
```
Launch controllers and some other things:
```
roslaunch simple_ros_control_main arm_ros_control.launch
```
Run the main control node:
```
rosrun simple_ros_control_main simple_ros_control_main
```
Launch moveit:
```
roslaunch simple_ros_control_main moveit_bringup.launch
```

Drag the robot arm, and then press **plan and execuate**, you can see the joints and actuators value change in the terminal running **simple_ros_control_main** node. The actuator values shown will be passed to the **communication_interface**. So you can use these values to write into your motors.
