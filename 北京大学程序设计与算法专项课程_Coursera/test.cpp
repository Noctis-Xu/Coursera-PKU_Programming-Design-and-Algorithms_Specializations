#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <cstdio>
//#include <cstdlib>
#include <string.h>

using namespace std;
class A {
public:
	int v;
	A(int n) {
		v = n;
		cout << "constructed" << endl;
	}
	A(const A& a) {
		v = a.v;
		cout << "test" << endl;
	}
	void func();
	~A() {
		cout << "deleted" << endl;
	}
};
void A::func() {
	cout << 1 << endl;
}

class MyClass
{
public:
	static MyClass object;
	char str[22] = "Matryoshka Prohibited";
	//balabala...
} foo, bar;

MyClass MyClass::object;

int main() {
	/*A *p=new A(5);
	delete p;
	cout << MyClass::object.object.object.str<<endl;
	cout<<sizeof(foo)<<endl;
	cout << sizeof(MyClass::object.object) << endl;*/

	int* p = new int[3, 4];
	p[0, 0] = 1;
	p[0, 1] = 2;
	p[0, 2] = 3;
	p[0, 3] = 4;
	p[1,0] = 5;
	
	cout << p[0, 0] << endl << p[0, 1] << endl;
	//cout << p[1, 0] << endl;
	cout << p[4] << endl;
	delete[] p;
	return 0;

	
}
