# /src/sort_algorithms/CMakeLists.txt

# 添加排序算法的实现文件
set(SORT_ALGORITHMS_SOURCE
    sort.h sort.cpp
)

# 创建排序算法库
add_library(SortAlgorithms ${SORT_ALGORITHMS_SOURCE})
