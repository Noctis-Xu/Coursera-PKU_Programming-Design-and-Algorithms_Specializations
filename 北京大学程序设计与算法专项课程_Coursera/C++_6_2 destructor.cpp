/*���������������ǣ�

destructor B
destructor A

������д�� class A�� ��������������Ϊ class A ��д���캯����
*/
#include <iostream>
using namespace std;
class A {
    // �ڴ˴�������Ĵ���
public:
    virtual ~A() { cout << "destructor A" << endl; }
};
class B :public A {
public:
    ~B() { cout << "destructor B" << endl; }
};
int main() {
    A* pa;
    pa = new B;
    delete pa;
    return 0;
}