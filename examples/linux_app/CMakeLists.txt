cmake_minimum_required(VERSION 3.1)

project(linux_app)

add_executable(linux_app main.cpp)
target_link_libraries(linux_app oakplayer)
