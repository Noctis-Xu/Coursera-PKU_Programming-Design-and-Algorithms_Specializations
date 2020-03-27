#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	int a, b, c;
	scanf("%d,%d,%d", &a, &b, &c);
	if (a + b == c) 
		cout << '+';
	else if (a - b == c)
		cout << '-';
	else if (a * b == c) 
		cout << '*';
	else if (a / b == c && a % b == 0) 
		cout << '/';
	else if (a % b == c) 
		cout << '%';
	else 
		cout << "error";

	return 0;
}
