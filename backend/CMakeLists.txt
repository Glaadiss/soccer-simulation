cmake_minimum_required(VERSION 3.6)
project(backend)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Playground.cpp Playground.h MovableObject.cpp MovableObject.h Ball.cpp Ball.h Goal.cpp Goal.h Team.cpp Team.h PointsTable.cpp PointsTable.h Bot.cpp Bot.h Attacker.cpp Attacker.h Deffender.cpp Deffender.h)
add_executable(backend ${SOURCE_FILES})