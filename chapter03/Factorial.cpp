//
// Created by Kafka on 2023/7/18.
//
#include <iostream>

using namespace std;

/**
 * 递归求阶乘
 * @param x
 * @return
 */
int Factorial(int x) {
    if (x == 1) {   // 基线条件，不再调用自己
        return 1;
    } else {    // 递归条件，调用自己
        return x * Factorial(x - 1);
    }
}

int main() {
    cout << Factorial(5);
    return 0;
}