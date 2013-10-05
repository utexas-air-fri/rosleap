# About

This package allows publishing of ROS messages with position and pitch/roll/yaw information from the first hand in the frame from a Leap Motion device. Messages are published on topic /leap. The eventual goal is to use this as an interface for controlling ARDrone quadrotors.

# Dependencies

This package depends on the header files and shared object from the [Leap Motion SDK](https://www.leapmotion.com/developers), which are not included here for licensing reasons. The directories that should be present are:

* include/Leap.h
* include/LeapMath.h
* lib/libLeap.so
