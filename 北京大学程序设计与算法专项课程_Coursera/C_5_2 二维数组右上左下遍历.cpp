#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <string.h> //strlenº¯Êý

using namespace std;

int main() {
	int row, col;
	//int array[100][100];
	//int(*p)[100] = array;
	cin >> row >> col;
	int** p = new int* [row];
	for (int i = 0; i < row; i++) {
		p[i] = new int[col];
	}

	//input
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> p[i][j];
		}
	}
	//process
	for (int i = 0; i < row + col - 1; i++) {
		int k = i;
		for (int j = 0; j <= i; j++) {
			if (j < row && k < col) {
				cout << p[j][k] << endl;
			}
			k--;
		}
	}

	for (int i = 0; i < row; i++) {
		delete[] p[i];
	}
	delete[] p;

	return 0;
}