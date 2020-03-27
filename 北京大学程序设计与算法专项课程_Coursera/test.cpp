#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <string.h> //strlenº¯Êý
#include <math.h>

using namespace std;


int main() {
	char a[10] = "hello";
	char* p = a;
	p[1] = 'c';
	cout << a << endl;
	char* pc = p;
	pc[2] = 'd';
	cout << a << endl;

}
