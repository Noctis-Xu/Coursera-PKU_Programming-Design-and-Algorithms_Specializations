#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define SELF p[i][j]
#define UP p[i-1][j]
#define DOWN p[i+1][j]
#define LEFT p[i][j-1]
#define RIGHT p[i][j+1]

int main() {
	int m, n;
	cin >> m >> n;
	double** p = new double* [m];
	for (int i = 0; i < m; i++) {
		p[i] = new double[n];
	}

	//input
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}

	if (n >= 5 && m >= 5) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i != 0 && i != m - 1 && j != 0 && j != n - 1) {//非边界元素
					if (SELF >= UP && SELF >= DOWN && SELF >= LEFT && SELF >= RIGHT) {
						printf("%d %d\n", i, j);
					}
				}
				if (i == 0 && j == 0) {//左上角元素
					if (SELF >= DOWN && SELF >= RIGHT) {
						printf("%d %d\n", i, j);
					}
				}
				if (i == 0 && j == n - 1) {//右上角
					if (p[i][j] >= p[i + 1][j] && p[i][j] >= p[i][j - 1]) {
						printf("%d %d\n", i, j);
					}
				}
				if (i == m - 1 && j == 0) {//左下角
					if (p[i][j] >= p[i - 1][j] && p[i][j] >= p[i][j + 1]) {
						printf("%d %d\n", i, j);
					}
				}
				if (i == m - 1 && j == n - 1) {//右下角
					if (p[i][j] >= p[i - 1][j] && p[i][j] >= p[i][j - 1]) {
						printf("%d %d\n", i, j);
					}
				}
				if (i == 0 && j != 0 && j != n - 1) {//第一行不包括角
					if (SELF >= DOWN && SELF >= LEFT && SELF >= RIGHT) {
						printf("%d %d\n", i, j);
					}
				}
				if (i == m - 1 && j != 0 && j != n - 1) {//最后一行不包括角
					if (SELF >= UP && SELF >= LEFT && SELF >= RIGHT) {
						printf("%d %d\n", i, j);
					}
				}
				if (i != 0 && i != m - 1 && j == 0) {//第一列不包括角
					if (SELF >= UP && SELF >= DOWN && SELF >= RIGHT) {
						printf("%d %d\n", i, j);
					}
				}
				if (i != 0 && i != m - 1 && j == n - 1) {//最后一列不包括角
					if (SELF >= UP && SELF >= DOWN && SELF >= LEFT) {
						printf("%d %d\n", i, j);
					}
				}
			}
		}
	}


	for (int i = 0; i < m; i++) {
		delete[]p[i];
	}
	delete[]p;
	return 0;
}