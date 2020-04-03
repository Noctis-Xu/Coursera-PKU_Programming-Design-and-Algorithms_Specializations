#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <cstdio>
//#include <cstdlib>
#include <string.h>

using namespace std;

int main() {
	class Student {
	private:
		char name[20], Sno[20], temp;
		unsigned int age, grade1, grade2, grade3, grade4, average_grade;
	public:
		void init(char* name_, unsigned int age_, char* Sno_, unsigned int grade1_, unsigned int grade2_, unsigned int grade3_, unsigned int grade4_) {
			strcpy(name,name_);
			strcpy(Sno, Sno_);
			age = age_;
			average_grade = (grade1_ + grade2_ + grade3_ + grade4_) / 4;
		}
		void Avrg() {
			cout << name << ',' << age << ',' << Sno << ',' << average_grade << endl;
		}
	};
	Student a;
	char name[20] = { '\0' }, Sno[20]= { '\0' }, tempc;
	unsigned int age, grade1, grade2, grade3, grade4, average_grade;

	tempc = getchar();
	for (int i = 0; tempc !=','; i++) {//name赋值
		name[i] = tempc;
		tempc = getchar();
	}
	cin >> age;//age赋值
	getchar();
	tempc = getchar();
	for (int i = 0; tempc != ','; i++) {//Sno赋值
		Sno[i] = tempc;
		tempc = getchar();
	}
	scanf("%u,%u,%u,%u", &grade1, &grade2, &grade3, &grade4);//grade赋值

	a.init(name,age,Sno, grade1, grade2, grade3, grade4);
	a.Avrg();
	return 0;
}