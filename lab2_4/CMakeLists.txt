cmake_minimum_required(VERSION 3.24)
project(lab2_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2_4 UdpPacketParser.h TcpPacketParser.h TcpPacketParser.cpp UdpPacketParser.cpp PacketParser.cpp PacketParser.h PacketParserMain.cpp)
