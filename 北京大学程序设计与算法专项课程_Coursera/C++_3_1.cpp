/*
����
��

���
0
5
*/
/*�ύ����ʱֻ�ύ
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
    cout << a.val << endl;//���0
    a.GetObj() = 5;//�����޸�a.val��ֵΪ5
    cout << a.val << endl;//���5
    return 0;
}