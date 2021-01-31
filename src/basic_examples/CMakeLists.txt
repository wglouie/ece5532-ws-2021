cmake_minimum_required(VERSION 2.8.3)
project(basic_examples)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  dynamic_reconfigure
)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_service_files(FILES Adder.srv)
generate_messages()

generate_dynamic_reconfigure_options(cfg/ReconfigExample.cfg)

catkin_package()

add_executable(topic_publisher src/topic_publisher.cpp)
target_link_libraries(topic_publisher ${catkin_LIBRARIES})

add_executable(service_advertiser src/service_advertiser.cpp)
add_dependencies(service_advertiser ${PROJECT_NAME}_gencpp)
target_link_libraries(service_advertiser ${catkin_LIBRARIES})

add_executable(service_client src/service_client.cpp)
add_dependencies(service_client ${PROJECT_NAME}_gencpp)
target_link_libraries(service_client ${catkin_LIBRARIES})

add_executable(namespace_example src/namespace_example.cpp)
target_link_libraries(namespace_example ${catkin_LIBRARIES})

add_executable(time_example src/time_example.cpp)
target_link_libraries(time_example ${catkin_LIBRARIES})

add_executable(message_stamped src/message_stamped.cpp)
target_link_libraries(message_stamped ${catkin_LIBRARIES})

add_executable(timer_example src/timer_example.cpp)
target_link_libraries(timer_example ${catkin_LIBRARIES})

add_executable(static_param_example src/static_param_example.cpp)
target_link_libraries(static_param_example ${catkin_LIBRARIES})

add_executable(dynamic_param_example src/dynamic_param_example.cpp)
add_dependencies(dynamic_param_example ${PROJECT_NAME}_gencfg)
target_link_libraries(dynamic_param_example ${catkin_LIBRARIES})
