#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String  # Import String message type from std_msgs package
import sys, tty, termios

class KeyboardController(Node):
    def __init__(self):
        super().__init__('keyboard_controller')
        self.publisher = self.create_publisher(String, 'robot_commands', 10)  # Publish String messages
        self.timer_period = 0.1  # seconds
        self.timer = self.create_timer(self.timer_period, self.keyboard_input)
        self.shut_node = False

    def keyboard_input(self):
        # Read keyboard inputw
        tty.setcbreak(sys.stdin.fileno())
        self.key = sys.stdin.read(1)

        # self.key = input("Enter the input command : ")

        # Print the key pressed
        print(f"Key pressed: {self.key}")

        # Map keyboard input to robot commands
        if self.key == 'w':
            command = 'F'
        elif self.key == 'a':
            command = 'L'
        elif self.key == 's':
            command = 'B'
        elif self.key == 'd':
            command = 'R'
        else:
            command = None

        # Print the mapped command
        if command:
            print(f"Mapped command: {command}")

        # Publish the mapped command as a string message
        if command:
            msg = String()
            msg.data = command
            self.publisher.publish(msg)

        # Shutdown the node if 'q' is pressed
        if self.key == 'q':
            self.timer.cancel()
            self.shut_node = True


def main(args=None):

    rclpy.init(args=args)
    keyboard_controller = KeyboardController()

    while not keyboard_controller.shut_node:
        rclpy.spin_once(keyboard_controller)
        
    rclpy.shutdown()


if __name__ == '__main__':
    main()
