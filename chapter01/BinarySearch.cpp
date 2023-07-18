//
// Created by Kafka on 2023/7/17.
//

#include <iostream>

using namespace std;

/**
 * 二分查找
 * @param arr
 * @param length
 * @param item
 * @return 找不到返回-1
 */
int BinarySearch(const int arr[], int length, int item) {
    int left = 0, right = length - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == item) {
            return static_cast<int>(mid);
        } else if (arr[mid] < item) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(arr[0]);
    int item = 1;
    cout << BinarySearch(arr, length, item);
    return 0;
}
