cmake_minimum_required(VERSION 4.0)
project(SimpleStateMachine)

set(CMAKE_CXX_STANDARD 26)

add_executable(SimpleStateMachine main.cpp
        Tests/Test.cpp
        Tests/Test.h
        StateMachine/FSM.cpp
        StateMachine/FSM.h
        StateMachine/States.h
        StateMachine/Events.h)
