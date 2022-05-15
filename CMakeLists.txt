cmake_minimum_required(VERSION 3.20)
project(CatLog)

set(CMAKE_CXX_STANDARD 14)
# 添加子库
add_subdirectory(leveldb)
add_executable(${PROJECT_NAME} main.cpp)

# 链接子工程

target_link_libraries(${PROJECT_NAME} leveldb)
