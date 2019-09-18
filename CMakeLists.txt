cmake_minimum_required(VERSION 3.0)	

project(ObjectPool)	
set(CMAKE_CXX_STANDARD 14)	

add_executable(ObjectPool main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(ObjectPool Threads::Threads)