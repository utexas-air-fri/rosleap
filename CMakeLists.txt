cmake_minimum_required(VERSION 2.8.3)
project(rosleap)
find_package(catkin REQUIRED COMPONENTS 
    roscpp
	std_msgs
	geometry_msgs
	message_generation)
add_message_files(FILES
	leap.msg
)
generate_messages(DEPENDENCIES
	std_msgs
	geometry_msgs
)
catkin_package()

include_directories(${PROJECT_SOURCE_DIR}/include/)
link_directories(${PROJECT_SOURCE_DIR}/lib/)
add_executable(rosleap src/rosleap.cpp)
target_link_libraries(rosleap ${catkin_LIBRARIES} Leap)
install(TARGETS rosleap RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
add_dependencies(rosleap ${catkin_EXPORTED_TARGETS})

