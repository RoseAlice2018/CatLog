cmake_minimum_required(VERSION 3.20)
project(CatLog)

set(CMAKE_CXX_STANDARD 14)
find_package(yaml-cpp REQUIRED)
find_package(Boost 1.76.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${YAML_CPP_LIBRARY_DIRS}) # 添加yaml-cpp库文件路径
# 添加子库
add_subdirectory(leveldb)
add_subdirectory(Log)
add_executable(${PROJECT_NAME} main.cpp)

# 链接子工程

target_link_libraries(${PROJECT_NAME} leveldb Log ${Boost_LIBRARIES} ${YAML_CPP_LIBRARIES})
