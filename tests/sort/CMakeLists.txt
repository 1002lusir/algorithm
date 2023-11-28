cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Test REQUIRED)

# 添加链接库搜索路径
link_directories("${CMAKE_BINARY_DIR}/src/sort")

# 添加排序算法的实现文件
set(SORT_ALGORITHMS_SOURCE
    testsort.h testsort.cpp
)

# 生成应用程序
ADD_EXECUTABLE(TestSort ${SORT_ALGORITHMS_SOURCE})

target_include_directories(TestSort PRIVATE  ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(TestSort Qt6::Core Qt6::Test)

target_link_libraries(TestSort libSortAlgorithms.a)



