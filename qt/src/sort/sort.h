#ifndef SORT_H
#define SORT_H

#include <cstdint>
#include <vector>

class Sort
{
public:
    virtual void PositiveSort(std::vector<int32_t> &n_numbers) = 0;
    virtual void InvertedSort(std::vector<int32_t> &n_numbers) = 0;
};

class BubbleSort : public Sort
{
public:
    void PositiveSort(std::vector<int32_t> &n_numbers) override;
    void InvertedSort(std::vector<int32_t> &n_numbers) override;
};

class SelectSort : public Sort
{
public:
    void PositiveSort(std::vector<int32_t> &n_numbers) override;
    void InvertedSort(std::vector<int32_t> &n_numbers) override;
};

class InsertSort : public Sort
{
public:
    void PositiveSort(std::vector<int32_t> &n_numbers) override;
    void InvertedSort(std::vector<int32_t> &n_numbers) override;
};

class ShellSort : public Sort
{
public:
    void PositiveSort(std::vector<int32_t> &n_numbers) override;
    void InvertedSort(std::vector<int32_t> &n_numbers) override;
};

class MergeSort : public Sort
{
public:
    void PositiveSort(std::vector<int32_t> &n_numbers) override;
    void InvertedSort(std::vector<int32_t> &n_numbers) override;

private:
    void merge(std::vector<int32_t>& arr, int left, int middle, int right);
};

class QuickSort : public Sort
{
public:
    void PositiveSort(std::vector<int32_t> &n_numbers) override;
    void InvertedSort(std::vector<int32_t> &n_numbers) override;
};

class HeapSort : public Sort
{
public:
    void PositiveSort(std::vector<int32_t> &n_numbers) override;
    void InvertedSort(std::vector<int32_t> &n_numbers) override;

private:
    void AdjustMaxHeap(std::vector<int32_t> &n_numbers, int32_t n_start_index, int32_t n_end_index);

    void AdjustMinHeap(std::vector<int32_t> &n_numbers, int32_t n_start_index, int32_t n_end_index);
};

#endif // SORT_H
