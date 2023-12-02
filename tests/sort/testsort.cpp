#include "testsort.h"

#include <random>
#include <qtestcase.h>

#include "sort/sort.h"

std::vector<int32_t> TestSort::CreateTestData()
{
    // 使用 C++11 中引入的 <random> 头文件来生成随机数
    std::random_device rd;  // 用于获取随机数种子
    std::mt19937 gen(rd()); // 使用 Mersenne Twister 引擎

    std::vector<int32_t> randomVector;

    // 生成长度为50的随机数组
    for (int i = 0; i < 50; ++i) {
        std::uniform_int_distribution<int32_t> dis(std::numeric_limits<int32_t>::min(),
                                                   std::numeric_limits<int32_t>::max());
        randomVector.push_back(dis(gen));
    }
    return randomVector;
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

void TestSort::testShellSort()
{
    ShellSort sort;
    std::vector<int32_t> data = CreateTestData();
    sort.PositiveSort(data);
    QCOMPARE(VerifyPosSort(data), true);
    sort.InvertedSort(data);
    QCOMPARE(VerifyInrevSort(data), true);
}

void TestSort::testMergeSort()
{
    MergeSort sort;
    std::vector<int32_t> data = CreateTestData();
    sort.PositiveSort(data);
    QCOMPARE(VerifyPosSort(data), true);
    sort.InvertedSort(data);
    QCOMPARE(VerifyInrevSort(data), true);
}

void TestSort::testQuickSort()
{

    QuickSort sort;
    std::vector<int32_t> data = CreateTestData();
    sort.PositiveSort(data);
    QCOMPARE(VerifyPosSort(data), true);
    sort.InvertedSort(data);
    QCOMPARE(VerifyInrevSort(data), true);
}

void TestSort::testHeapSort()
{
    HeapSort sort;
    std::vector<int32_t> data = CreateTestData();
    sort.PositiveSort(data);
    QCOMPARE(VerifyPosSort(data), true);
    sort.InvertedSort(data);
    QCOMPARE(VerifyInrevSort(data), true);
}

QTEST_MAIN(TestSort)
