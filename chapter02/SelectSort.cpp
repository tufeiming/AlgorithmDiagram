//
// Created by Kafka on 2023/7/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/**
 * 选择排序
 * @param vec 待排序向量
 */
void SelectSort(vector<int> &vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec.at(i) > vec.at(j)) {
                int temp = vec.at(i);
                vec[i] = vec.at(j);
                vec[j] = temp;
            }
        }
    }
}


int main() {
    vector<int> vec = {4, 3, 9, 6, 7, 7};
    SelectSort(vec);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    return 0;
}