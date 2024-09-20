package main

import (
	"fmt"

	"example.com/m/sorting"
)

func main() {
	arr := []int{5, 2, 9, 1, 5, 6}
	fmt.Println("Original array:", arr)

	sortedBubble := sorting.BubbleSort(arr)
	fmt.Println("Bubble sorted:", sortedBubble)

	sortedInsertion := sorting.InsertionSort(arr)
	fmt.Println("Insertion sorted:", sortedInsertion)

	// 可以在这里调用其他排序算法进行展示
}
