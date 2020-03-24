#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <string.h> //strlenº¯Êý

using namespace std;

int main() {
	int n;
	cin >> n;
	char** p = new char* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new char[256];
	}

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; p[i][j] !='\0'; j++) {
			switch (p[i][j])
			{
			case 'A': p[i][j] = 'T'; break;
			case 'T': p[i][j] = 'A'; break;
			case 'C': p[i][j] = 'G'; break;
			case 'G': p[i][j] = 'C'; break;
			default:
				break;
			}
		}
		cout << p[i]<<endl;
	}

	for (int i = 0; i < n; i++) {
		delete[]p[i];
	}
	delete[]p;
	return 0;
}