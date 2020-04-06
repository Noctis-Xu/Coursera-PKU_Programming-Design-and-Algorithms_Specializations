/*
输入
无

输出
0
5
*/
/*提交代码时只提交
A(int n = 0) { val = n; }
int& GetObj() {
    return val;
}
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class A {
public:
    int val;
    A(int n=0) { val = n; }
    int & GetObj() {
        return val;
    }
};

int main() {
    A a;
    cout << a.val << endl;//输出0
    a.GetObj() = 5;//这里修改a.val的值为5
    cout << a.val << endl;//输出5
    return 0;
}