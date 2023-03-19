cmake_minimum_required(VERSION 3.24)
project(lab2_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2_3 AmazonMain.cpp Book.h DVD.h DigitalMusic.h DigitalMusic.cpp Book.cpp DVD.cpp GenericType.h GenericType.cpp)
