cmake_minimum_required(VERSION 3.0)	

project(thread_join_detach)	
set(CMAKE_CXX_STANDARD 14)	

add_executable(thread_join_detach main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(thread_join_detach Threads::Threads)