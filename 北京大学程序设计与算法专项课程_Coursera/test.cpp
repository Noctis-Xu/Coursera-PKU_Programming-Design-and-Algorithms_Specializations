#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string>
//#include <cstdio>
//#include <cstdlib>
//#include <string.h>
#include <cstring>

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

class base {
public:
	int n;
	virtual void func() {
		printf("base\n");
	}
	virtual void func2() = 0;
	virtual ~base() { cout << "base" << endl; };
	base() { };
};
class Derived :public base {
	~Derived() { cout << "derived" << endl; }
	void func2() {};
};


class B {
private:
	int nBVal;
public:
	int i;
};

class D :public B{
public:
	int a;
};

int main() {
	//string array[4] = { "Tom","Jack","Mary","John" };
	string array[3] = { "Tom","Jack","Mary" };
	//int a=countof(string);
	string* p1 = array, * p2 = array + 2;
	cout << p1 << endl << p2<<endl;
	int b = p2 - p1;
	cout << b;
}
