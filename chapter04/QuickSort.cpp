//
// Created by 涂飞明 on 2023/7/18.
//

#include <iostream>

using namespace std;

/**
 * 交换
 * @param arr
 * @param i
 * @param j
 */
void Swap(int arr[], size_t i, size_t j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/**
 * 分区，左边都比pivot小，右边都比pivot大
 * @param arr
 * @param left
 * @param right
 * @return pivot的索引
 */
int Partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j) {
        // 从右往左，找到第一个比pivot小的
        while (i < j && arr[j] >= pivot) {
            --j;
        }
        // 从左往右，找到第一个比pivot大的
        while (i < j && arr[i] <= pivot) {
            ++i;
        }
        if (i < j) {
            Swap(arr, i, j);
        }
    }
    // 此时i与j相等
    Swap(arr, left, i);
    return i;
}

/**
 * 快速排序
 * @param arr
 * @param left
 * @param right
 */
void QuickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = Partition(arr, left, right);
        // 这里有个坑，注意：如果size_t类型的0-1，会变成一个很大的数，而不是-1
        QuickSort(arr, left, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    int arr[] = {3, 4, 0, 5, 2, 6, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, length - 1);
    copy(cbegin(arr), cend(arr), ostream_iterator<int>(cout, " "));
    return 0;
}
