package sorting_test

import (
	"testing"

	"example.com/m/sorting"
)

func TestBubbleSort(t *testing.T) {
	arr := []int{5, 2, 9, 1, 5, 6}
	sorted := sorting.BubbleSort(arr)

	expected := []int{1, 2, 5, 5, 6, 9}
	for i, v := range sorted {
		if v != expected[i] {
			t.Errorf("Expected %v, got %v", expected, sorted)
		}
	}
}

func TestInsertionSort(t *testing.T) {
	arr := []int{4, 3, 2, 10, 12, 1, 5, 6}
	sorted := sorting.InsertionSort(arr)

	expected := []int{1, 2, 3, 4, 5, 6, 10, 12}
	for i, v := range sorted {
		if v != expected[i] {
			t.Errorf("Expected %v, got %v", expected, sorted)
		}
	}
}

// 其他排序算法的测试可以放在这里
