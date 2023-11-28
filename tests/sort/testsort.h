#ifndef TESTSORT_H
#define TESTSORT_H

#include <QObject>
#include <QTest>

class TestSort : public QObject
{
    Q_OBJECT

public:
    TestSort(){};

private:
    std::vector<int32_t> CreateTestData();

    bool VerifyPosSort(std::vector<int32_t> n_numbers);

    bool VerifyInrevSort(std::vector<int32_t> n_numbers);

private slots:
    void testBubbleSort();

    void testSelectSort();

    void testInsertSort();

};

#endif // TESTSORT_H
