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

	cout << Func().v << endl;
	return 0;

}
