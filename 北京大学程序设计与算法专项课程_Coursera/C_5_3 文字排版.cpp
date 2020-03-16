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
		p[i] = new char[40];
		cin >> p[i];
	}

	cout << p[0];
	int sum = strlen(p[0]);
	for (int i = 1; i < n; i++) {
		if ((sum + strlen(p[i])+1) <= 80) {
			cout << ' ' << p[i];
			sum = sum + strlen(p[i])+1;
		}
		else {
			cout << '\n' << p[i];
			sum = strlen(p[i]);
		}
	}
	cout << endl;

	//cin.getline(p,long long(n)*40);
	//for (int i = 0; p[i] != '\0'; ) {
	//	int j = i;
	//	while( p[j] != '\0' && p[j] != ' ') {
	//		j++;
	//	}
	//	int character = j - i;
	//	cout << character << endl;
	//	j++;
	//	i = j;
	//}

	for (int i = 0; i < n; i++) delete[] p[i];
	delete[]p;
	return 0;
}