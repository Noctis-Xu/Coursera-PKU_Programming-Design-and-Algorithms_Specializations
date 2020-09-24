//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h> //clock()
#include <Windows.h> //time(0), Sleep()

using namespace std;

int main() {
	int a = rand();
	cout << a << endl;

	srand(1);
	a = rand();
	cout << a << endl;

	srand(2);
	a = rand();
	cout << a << endl;
	srand(3);
	a = rand();
	cout << a << endl;
	
	cout << time(0) << endl;
	Sleep(800);
	cout << time(0) << endl;
	return 0;
}