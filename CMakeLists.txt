cmake_minimum_required(VERSION 3.3)
project(Tp_Cpp_5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Object.cpp src/Object.h src/Segment.cpp src/Segment.h src/Polygon.cpp src/Polygon.h src/Rectangle.cpp src/Rectangle.h src/Point.cpp src/Point.h src/Draw.cpp src/Draw.h)
add_executable(Tp_Cpp_5 ${SOURCE_FILES})