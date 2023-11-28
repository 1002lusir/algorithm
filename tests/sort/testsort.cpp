#include "testsort.h"

#include <qtestcase.h>

#include "sort/sort.h"

std::vector<int32_t> TestSort::CreateTestData()
{
    return std::vector<int32_t>{ 2,1,3,4,6,5,9,8,7,0 };
}

bool TestSort::VerifyPosSort(std::vector<int32_t> n_numbers)
{
    for (size_t i = 0; i < n_numbers.size() - 1; ++i) {
        if (n_numbers[i] > n_numbers[i + 1]) {
            return false;  // 如果发现当前元素大于下一个元素，说明数组无序
        }
    }
    return true;  // 数组升序
}

bool TestSort::VerifyInrevSort(std::vector<int32_t> n_numbers)
{
    for (size_t i = 0; i < n_numbers.size() - 1; ++i) {
        if (n_numbers[i] < n_numbers[i + 1]) {
            return false;  // 如果发现当前元素小于下一个元素，说明数组无序
        }
    }
    return true;  // 数组降序
}

void TestSort::testBubbleSort()
{
    BubbleSort sort;
    std::vector<int32_t> data = CreateTestData();
    sort.PositiveSort(data);
    QCOMPARE(VerifyPosSort(data), true);
    sort.InvertedSort(data);
    QCOMPARE(VerifyInrevSort(data), true);
}

void TestSort::testSelectSort()
{
    SelectSort sort;
    std::vector<int32_t> data = CreateTestData();
    sort.PositiveSort(data);
    QCOMPARE(VerifyPosSort(data), true);
    sort.InvertedSort(data);
    QCOMPARE(VerifyInrevSort(data), true);
}

void TestSort::testInsertSort()
{
    InsertSort sort;
    std::vector<int32_t> data = CreateTestData();
    sort.PositiveSort(data);
    QCOMPARE(VerifyPosSort(data), true);
    sort.InvertedSort(data);
    QCOMPARE(VerifyInrevSort(data), true);
}

QTEST_MAIN(TestSort)
