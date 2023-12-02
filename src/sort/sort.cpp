#include "sort.h"

void BubbleSort::PositiveSort(std::vector<int32_t> &n_numbers)
{
    for(size_t i = n_numbers.size(); i > 0; i--)
    {
        bool flag = false;
        for(size_t j = 0; j < i - 1; j++)
        {
            int32_t cur_number = n_numbers[j];
            if(cur_number > n_numbers[j+1])
            {
                n_numbers[j] = n_numbers[j+1];
                n_numbers[j+1] = cur_number;
                flag = true;
            }
        }
        if(flag == false)
        {
            return;
        }
    }
}

void BubbleSort::InvertedSort(std::vector<int32_t> &n_numbers)
{
    for(size_t i = n_numbers.size(); i > 0; i--)
    {
        bool flag = false;
        for(size_t j = 0; j < i - 1; j++)
        {
            int32_t cur_number = n_numbers[j];
            if(cur_number < n_numbers[j+1])
            {
                n_numbers[j] = n_numbers[j+1];
                n_numbers[j+1] = cur_number;
                flag = true;
            }
        }
        if(flag == false)
        {
            return;
        }
    }
}

void SelectSort::PositiveSort(std::vector<int32_t> &n_numbers)
{
    for(size_t i = 0; i < n_numbers.size(); i++)
    {
        size_t min_index = i;
        for(size_t j = i; j < n_numbers.size(); j++)
        {
            if(n_numbers[j] < n_numbers[min_index])
            {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            int32_t min_number = n_numbers[min_index];
            n_numbers[min_index] = n_numbers[i];
            n_numbers[i] = min_number;
        }
    }
}

void SelectSort::InvertedSort(std::vector<int32_t> &n_numbers)
{
    for(size_t i = 0; i < n_numbers.size(); i++)
    {
        size_t max_index = i;
        for(size_t j = i; j < n_numbers.size(); j++)
        {
            if(n_numbers[j] > n_numbers[max_index])
            {
                max_index = j;
            }
        }
        if(max_index != i)
        {
            int32_t min_number = n_numbers[max_index];
            n_numbers[max_index] = n_numbers[i];
            n_numbers[i] = min_number;
        }
    }
}

void InsertSort::PositiveSort(std::vector<int32_t> &n_numbers)
{
    for(size_t i = 1; i < n_numbers.size(); i++)
    {
        int32_t cur_number = n_numbers[i];
        int32_t j = i - 1;
        for(; j >= 0; j--)
        {
            if(n_numbers[j] > cur_number)
            {
                n_numbers[j+1] = n_numbers[j];
            }
            else
            {
                break;
            }
        }
        n_numbers[j+1] = cur_number;
    }
}

void InsertSort::InvertedSort(std::vector<int32_t> &n_numbers)
{
    for(size_t i = 1; i < n_numbers.size(); i++)
    {
        int32_t cur_number = n_numbers[i];
        int32_t j = i - 1;
        for(; j >= 0; j--)
        {
            if(n_numbers[j] < cur_number)
            {
                n_numbers[j+1] = n_numbers[j];
            }
            else
            {
                break;
            }
        }
        n_numbers[j+1] = cur_number;
    }
}

void ShellSort::PositiveSort(std::vector<int32_t> &n_numbers)
{
    for(int32_t gap = n_numbers.size()/2; gap > 0; gap/=2)
    {
        for(int32_t i = 0; i < gap; i++)
        {
            for(size_t j = i + gap; j < n_numbers.size(); j+=gap)
            {
                int32_t pro_index = j-gap;
                int32_t cur_number = n_numbers[j];
                if(cur_number < n_numbers[pro_index])
                {
                    while(pro_index >= 0 && cur_number < n_numbers[pro_index])
                    {
                        n_numbers[pro_index + gap] = n_numbers[pro_index];
                        pro_index -= gap;
                    }

                    n_numbers[pro_index + gap] = cur_number;
                }
            }
        }
    }
}

void ShellSort::InvertedSort(std::vector<int32_t> &n_numbers)
{
    for(int32_t gap = n_numbers.size()/2; gap > 0; gap/=2)
    {
        for(int32_t i = 0; i < gap; i++)
        {
            for(size_t j = i + gap; j < n_numbers.size(); j+=gap)
            {
                int32_t pro_index = j-gap;
                int32_t cur_number = n_numbers[j];
                if(cur_number > n_numbers[pro_index])
                {
                    while(pro_index >= 0 && cur_number > n_numbers[pro_index])
                    {
                        n_numbers[pro_index + gap] = n_numbers[pro_index];
                        pro_index -= gap;
                    }

                    n_numbers[pro_index + gap] = cur_number;
                }
            }
        }
    }
}

void MergeSort::PositiveSort(std::vector<int32_t> &n_numbers)
{
    if(n_numbers.size()>1)
    {
        auto middle = n_numbers.begin() + n_numbers.size() / 2;
        std::vector<int32_t> front_numbers(n_numbers.begin(), middle);
        std::vector<int32_t> last_numbers(middle, n_numbers.end());
        PositiveSort(front_numbers);
        PositiveSort(last_numbers);
        n_numbers.clear();
        size_t i = 0;
        size_t j = 0;
        while(i<front_numbers.size() && j<last_numbers.size())
        {
            if(front_numbers[i] < last_numbers[j])
            {
                n_numbers.push_back(front_numbers[i++]);
            }
            else
            {
                n_numbers.push_back(last_numbers[j++]);
            }
        }
        while(i<front_numbers.size())
        {
            n_numbers.push_back(front_numbers[i++]);
        }
        while(j<last_numbers.size())
        {
            n_numbers.push_back(last_numbers[j++]);
        }
    }
    else
    {
        return;
    }
}

void MergeSort::InvertedSort(std::vector<int32_t> &n_numbers)
{
    int n = n_numbers.size();

    // 按照当前子数组大小从1到n/2迭代
    for (int currentSize = 1; currentSize <= n - 1; currentSize = 2 * currentSize) {
        // 从左到右依次处理当前子数组
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currentSize) {
            int middle = std::min(leftStart + currentSize - 1, n - 1);
            int rightEnd = std::min(leftStart + 2 * currentSize - 1, n - 1);

            // 归并当前子数组
            merge(n_numbers, leftStart, middle, rightEnd);
        }
    }
}

void MergeSort::merge(std::vector<int32_t> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // 创建两个临时向量来存储左右两个子数组
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    // 复制数据到临时向量 leftArray[] 和 rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];

    // 归并临时向量到 arr[left..right]

    int i = 0; // 初始化左子数组的索引
    int j = 0; // 初始化右子数组的索引
    int k = left; // 初始化归并后数组的索引

    while (i < n1 && j < n2) {
        if (leftArray[i] >= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // 复制 leftArray[] 的剩余部分（如果有）
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // 复制 rightArray[] 的剩余部分（如果有）
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void QuickSort::PositiveSort(std::vector<int32_t> &n_numbers)
{
    if(n_numbers.empty())
    {
        return;
    }

    int32_t base_number = n_numbers[0];

    std::vector<int32_t> first_numbers;
    std::vector<int32_t> second_numbers;

    for(size_t i = 1; i < n_numbers.size(); i++)
    {
        if(n_numbers[i] < base_number)
        {
            first_numbers.push_back(n_numbers[i]);
        }
        else
        {
            second_numbers.push_back(n_numbers[i]);
        }
    }

    PositiveSort(first_numbers);

    PositiveSort(second_numbers);

    n_numbers.clear();

    for(int32_t number : first_numbers)
    {
        n_numbers.push_back(number);
    }

    n_numbers.push_back(base_number);

    for(int32_t number : second_numbers)
    {
        n_numbers.push_back(number);
    }

    return;
}

void QuickSort::InvertedSort(std::vector<int32_t> &n_numbers)
{
    if(n_numbers.empty())
    {
        return;
    }

    int32_t base_number = n_numbers[0];

    std::vector<int32_t> first_numbers;
    std::vector<int32_t> second_numbers;

    for(size_t i = 1; i < n_numbers.size(); i++)
    {
        if(n_numbers[i] > base_number)
        {
            first_numbers.push_back(n_numbers[i]);
        }
        else
        {
            second_numbers.push_back(n_numbers[i]);
        }
    }

    InvertedSort(first_numbers);

    InvertedSort(second_numbers);

    n_numbers.clear();

    for(int32_t number : first_numbers)
    {
        n_numbers.push_back(number);
    }

    n_numbers.push_back(base_number);

    for(int32_t number : second_numbers)
    {
        n_numbers.push_back(number);
    }

    return;
}

void HeapSort::PositiveSort(std::vector<int32_t> &n_numbers)
{
    //创建一次最大堆
    for(int32_t i = n_numbers.size() / 2 - 1; i >= 0 ; i--)
    {
        AdjustMaxHeap(n_numbers, i, n_numbers.size() - 1);
    }

    //将堆顶部的数据放到最后，对缩小一次的堆重新生成最大堆
    for(int32_t i = n_numbers.size() - 1; i > 0; i--)
    {
        std::swap(n_numbers[0], n_numbers[i]);
        AdjustMaxHeap(n_numbers, 0, i - 1);
    }
}

void HeapSort::InvertedSort(std::vector<int32_t> &n_numbers)
{
    //创建一次最小堆
    for(int32_t i = n_numbers.size() / 2 - 1; i >= 0 ; i--)
    {
        AdjustMinHeap(n_numbers, i, n_numbers.size() - 1);
    }

    //将堆顶部的数据放到最后，对缩小一次的堆重新生成最大堆
    for(int32_t i = n_numbers.size() - 1; i > 0; i--)
    {
        std::swap(n_numbers[0], n_numbers[i]);
        AdjustMinHeap(n_numbers, 0, i - 1);
    }
}

void HeapSort::AdjustMaxHeap(std::vector<int32_t> &n_numbers, int32_t n_start_index, int32_t n_end_index)
{
    int32_t dad = n_start_index;
    int32_t son = 2 * dad + 1;
    while(son<=n_end_index)
    {
        if(son + 1 <= n_end_index && n_numbers[son+1] > n_numbers[son])
        {
            son += 1;
        }
        if(n_numbers[dad] < n_numbers[son])
        {
            std::swap(n_numbers[dad], n_numbers[son]);
            dad = son;
            son = 2 * dad + 1;
        }
        else
        {
            return;
        }
    }
}

void HeapSort::AdjustMinHeap(std::vector<int32_t> &n_numbers, int32_t n_start_index, int32_t n_end_index)
{
    int32_t dad = n_start_index;
    int32_t son = 2 * dad + 1;
    while(son<=n_end_index)
    {
        if(son + 1 <= n_end_index && n_numbers[son+1] < n_numbers[son])
        {
            son += 1;
        }
        if(n_numbers[dad] > n_numbers[son])
        {
            std::swap(n_numbers[dad], n_numbers[son]);
            dad = son;
            son = 2 * dad + 1;
        }
        else
        {
            return;
        }
    }
}
