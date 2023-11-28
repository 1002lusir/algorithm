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
                n_numbers[j+1] = cur_number;
                break;
            }
        }
    }
}
