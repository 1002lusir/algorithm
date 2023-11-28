cmake_minimum_required(VERSION 3.10)

project(Algorithm)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加排序算法库
add_subdirectory(src/sort)

# 添加测试
enable_testing()
add_subdirectory(tests/sort)
