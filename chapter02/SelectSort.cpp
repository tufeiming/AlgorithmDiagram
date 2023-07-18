//
// Created by Kafka on 2023/7/17.
//

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

/**
 * 选择排序
 * @param arr
 * @param length
 */
void SelectSort(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main() {
    int arr[] = {4, 3, 9, 6, 7, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    SelectSort(arr, length);
    copy(cbegin(arr), cend(arr), ostream_iterator<int>(cout, " "));
    return 0;
}