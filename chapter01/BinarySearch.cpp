//
// Created by Kafka on 2023/7/17.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * 二分查找
 * @param vec 待查找向量
 * @param item 查找项
 * @return 索引，找不到返回-1
 */
int BinarySearch(const vector<int> &vec, int item) {
    size_t left = 0, right = vec.size() - 1;
    while (left <= right) {
        size_t mid = (left + right) / 2;
        if (vec.at(mid) == item) {
            return static_cast<int>(mid);
        } else if (vec.at(mid) < item) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> vec = {1, 3, 5, 7, 9};
    int item = 1;
    cout << BinarySearch(vec, item);
    return 0;
}
