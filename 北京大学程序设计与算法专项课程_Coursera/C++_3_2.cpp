/*
����
��

���
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
    // �ڴ˴�������Ĵ���
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}