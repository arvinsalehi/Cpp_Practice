cmake_minimum_required(VERSION 3.24)
project(assignment1)

set(CMAKE_CXX_STANDARD 17)

add_executable(assignment1 main.cpp Player.h Player.cpp Card.h PlayerYouth.h PlayerYouth.cpp DependantCard.h AttackCard.h CardGameAdapter.cpp CardGameAdapter.h CardGame.h CardGame.cpp PlayerAdult.h PlayerAdult.cpp)
