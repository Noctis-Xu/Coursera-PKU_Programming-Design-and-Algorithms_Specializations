#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>

using namespace std;

void PrintProcess(int a) {
	int temp = a;
	if (a == 1)
		cout << "End" << endl;
	else if (a % 2 == 1) {
		a = 3 * a + 1;
		printf("%d%s%d\n", temp, "*3+1=", a);
		PrintProcess(a);
	}
	else if (a % 2 == 0) {
		a = a / 2;
		printf("%d%s%d\n", temp, "/2=", a);
		//cout << temp << "/2=" << a << endl;
		PrintProcess(a);
	}
}

int main() {
	int a;
	cin >> a;
	PrintProcess(a);
	return 0;
}