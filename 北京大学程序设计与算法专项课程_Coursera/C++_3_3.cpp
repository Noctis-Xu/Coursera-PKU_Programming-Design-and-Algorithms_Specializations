/*
����
��

���
5,5
5,5
*/

#include <iostream>
using namespace std;
class Base {
public:
    int k;
    Base(int n) :k(n) { }
};
class Big {
public:
    int v; Base b;
    // �ڴ˴�������Ĵ���
    Big(int m) :v(m),b(m) { }//���캯��
    Big(const Big &m):v(m.v),b(m.b){ }//���ƹ��캯��
};
int main() {
    Big a1(5); Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}