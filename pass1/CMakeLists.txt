cmake_minimum_required(VERSION 3.10)
project(pass_1)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(pass_1
        main.cpp
        OperationInfomation.h
        OperationTable.cpp
        OperationTable.h InstructionLine.cpp InstructionLine.h)
