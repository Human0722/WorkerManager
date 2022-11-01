cmake_minimum_required(VERSION 3.22)
project(WorkerManager)

set(CMAKE_CXX_STANDARD 11)

#add_executable(WorkerManager test/test.cpp src/WorkerManager.cpp src/Employee.cpp src/Manager.cpp src/Boss.cpp)
add_executable(WorkerManager main.cpp src/Employee.cpp src/Boss.cpp src/Manager.cpp src/WorkerManager.cpp)