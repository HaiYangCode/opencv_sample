cmake_minimum_required(VERSION 3.22.1)
project("opencv_sample")
set(CMAKE_CXX_STANDARD 11)
#创建一个变量叫source_file ,指向当前目录下的所有.cpp文件


# 添加 OpenCV 库
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
message("OpenCV_INCLUDE_DIRS == ${OpenCV_INCLUDE_DIRS}")

message("CMAKE_SOURCE_DIR == ${CMAKE_SOURCE_DIR}")
file(GLOB source_file_cpp ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(
        opencv_sample #生成的库的名字
        ${source_file_cpp})#编译的源文件，如果是多个则依次写在后面，这里是用到了相对路径，如果其他目录需要指定路径

# find_library( # Sets the name of the path variable.
#         log-lib
#         # Specifies the name of the NDK library that
#         # you want CMake to locate.
#         log)
message("message == ${OpenCV_LIBS}")
target_link_libraries(opencv_sample ${OpenCV_LIBS})