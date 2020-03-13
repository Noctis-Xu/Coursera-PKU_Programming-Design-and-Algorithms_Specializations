#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <string.h> //strlenº¯Êý

using namespace std;

int main() {
	int number;
	int m = 0, n = 0;
	cin >> number;

	for (int i = 0; i < number; i++) {
		int sum=0;
		cin >> m >> n;
		int** p = new int* [m];
		for (int t = 0; t < m; t++) {
			p[t] = new int[n];
		}

		//input
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				cin >> p[j][k]; 
			}
		}

		//process
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (j == 0||j==m-1) {
					sum = sum + p[j][k];
				}
				else if ((j!=0&&j!=m-1)&&(k==0||k==n-1)) {
					sum = sum + p[j][k];
				}
			}
		}
		//output
		cout << sum << endl;

		for (int t = 0; t < m; t++) {
			delete[] p[t];
		}
		delete[] p;
	}

	return 0;
}