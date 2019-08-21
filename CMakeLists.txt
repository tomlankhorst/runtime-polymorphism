cmake_minimum_required(VERSION 3.10)
project(rtpoly)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(rtpoly main.cpp)
target_link_libraries(rtpoly Threads::Threads)
