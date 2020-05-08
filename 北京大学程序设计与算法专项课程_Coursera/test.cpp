#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

int main() {
	char s[50] = "1234567890";
	/*char* p1 = s;
	char* p2 = s + 2;
	memcpy(p1, p2, 5);
	cout << p1 << endl;
	_strrev(s);
	cout << s<<endl;
	cout << strlen(s) << endl;*/
	char s2[50] = { 'a' };
	strcpy(&s2[1], &s[10]);
	cout << s2;

	return 0;
}
