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
	A(int n) { v = n; }
	A(const A& a) {
		v = a.v;
		cout << "test" << endl;
	}
};
A Func() {
	A b(4);
	return b;
};
int main() {
	A test1(5);
	int a = 1, b = 2, c = 3;
	a = b = c;
	cout << &test1.v << endl << &test1 << endl;
}
