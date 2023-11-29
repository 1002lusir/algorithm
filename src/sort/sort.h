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

#endif // SORT_H
