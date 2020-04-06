/*
输入
无

输出
10
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class Sample {
public:
    int v;
    Sample(int n) :v(n) { }
    // 在此处补充你的代码
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}