# Project Goal
The project aims to develop a two-wheeled differential drive robot controlled using ROS 2. The robot is designed to be controlled via keyboard teleoperation, where key inputs are mapped to specific robot movements. The project also explores the implementation of a PID controller for motor control, enabling smoother and more precise movement. Additionally, the project lays the foundation for future enhancements, such as integrating SLAM (Simultaneous Localization and Mapping), computer vision, and AI applications.

# Tech Stack 

![ROS Logo](https://upload.wikimedia.org/wikipedia/commons/thumb/b/bb/Ros_logo.svg/50px-Ros_logo.svg.png) 
![Arduino Logo](https://upload.wikimedia.org/wikipedia/commons/thumb/8/87/Arduino_Logo.svg/50px-Arduino_Logo.svg.png) 
![Raspberry Pi Logo]([https://www.pngwing.com/en/search?q=raspberry+Pi](https://w7.pngwing.com/pngs/918/521/png-transparent-raspberry-pi-foundation-computer-usb-linux-computer-food-computer-logo-thumbnail.png))


# Introduction
The robot operates on a differential drive system, which consists of two independently driven wheels. By controlling the speed and direction of each wheel, the robot can move in various directions, including forward, backward, left, and right. The use of ROS 2 provides a modular and scalable framework for developing and controlling robotic systems, facilitating integration with sensors, actuators, and higher-level algorithms. 

The project involves a simple simulation on Gazebo but the major focus is on building real-time working DIY robot using minimal hardware cost. It also emphasises the power,speed,accuracy and low-latency response of ROS2 middleware communication 

# Hardware
- Two DC motors connected to an L298N motor driver for motor control.
- 12V Supply (Power Bank)
- 7V supply for motors and L298N 
- Raspberry Pi 4 serving as the main computing unit.
- Arduino board for interfacing with the motor driver and serial communication with the Raspberry Pi.
- Encoders (optional) for providing feedback on wheel positions.

# Workflow 

![ROS2_controlled_teleoperation drawio (1)](https://github.com/TahsinOP/ROS2_2WD_DIFF_DRIVE_ROBOT/assets/117567813/0fb5b0b3-2b1a-4344-8918-5cb9a7c15457)

1. **Setup and Configuration:**
   - Install ROS 2 on the Raspberry Pi.
   - Configure the Arduino for serial communication with the Raspberry Pi.
   
2. **Teleoperation Node:**
   - Develop a ROS 2 node on the main PC for keyboard teleoperation.
   - Map keyboard inputs (WASD) to robot commands (Forward, Left, Backward, Right, Stop).
   - Publish robot commands to the `robot_commands` topic.
   
3. **Serial Communication Node:**
   - Create a ROS 2 node on the Raspberry Pi to subscribe to the `robot_commands` topic.
   - Receive robot commands and transmit them to the Arduino via serial communication.

4. **Arduino Code:**
   - Implement Arduino code to interpret serial commands and control the motors accordingly.
   - Optionally, integrate a PID controller for smoother motor control using encoder feedback (if available).
  
# Demonstration 
## 
     
# Applications
- Educational purposes: Provides a hands-on learning experience for understanding robotics, ROS 2, and PID control.
- Research and prototyping: Enables rapid prototyping and experimentation with robotic systems.
- Hobby projects: Offers enthusiasts the opportunity to build and customize their own robot platforms for various applications.

# Improvements: Adding SLAM, Computer Vision, and AI Applications
1. **SLAM (Simultaneous Localization and Mapping):**
   - Integrate SLAM algorithms to enable the robot to map its environment and localize itself within it.
   - Use sensors such as LiDAR or depth cameras for environment perception.

2. **Computer Vision:**
   - Implement computer vision algorithms for object detection, tracking, and recognition.
   - Utilize cameras mounted on the robot for visual perception tasks.

3. **AI Applications:**
   - Explore AI techniques for autonomous navigation and decision-making.
   - Develop reinforcement learning algorithms for adaptive and self-improving robot behaviors.

By incorporating these enhancements, the robot can become more autonomous and capable of performing complex tasks in dynamic environments. These improvements open up possibilities for applications in areas such as autonomous mobile robots, robotic exploration, and human-robot interaction.
