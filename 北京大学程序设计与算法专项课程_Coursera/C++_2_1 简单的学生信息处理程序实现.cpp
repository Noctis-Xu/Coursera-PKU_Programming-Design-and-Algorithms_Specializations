#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	class Student {
	private:
		char name[20] = { '\0' }, Sno[20] = { '\0' }, tempc;
		unsigned int age, grade1, grade2, grade3, grade4, average_grade;

	public:
		void init() {
			//��1
			//tempc = getchar();
			//for (int i = 0; tempc != ','; i++) {//name��ֵ
			//	name[i] = tempc;
			//	tempc = getchar();
			//}
			//cin >> age;//age��ֵ
			//getchar();//����','
			//tempc = getchar();//����Sno�ĵ�һ���ַ�
			//for (int i = 0; tempc != ','; i++) {//Sno��ֵ
			//	Sno[i] = tempc;
			//	tempc = getchar();
			//}
			//scanf("%u,%u,%u,%u", &grade1, &grade2, &grade3, &grade4);//grade��ֵ
			//��2
			//scanf_s("%[^,],%u,%[^,],%u,%u,%u,%u", name,20,&age,Sno,20,&grade1, &grade2, &grade3, &grade4);//д��1
			//scanf("%[^,]%*c%u%*c%[^,]%*c%u%*c%u%*c%u%*c%u", name, &age, Sno, &grade1, &grade2, &grade3, &grade4);//д��2
			scanf("%[^,],%u,%[^,],%u,%u,%u,%u", name, &age, Sno, &grade1, &grade2, &grade3, &grade4);//д��3
			average_grade = (grade1 + grade2 + grade3 + grade4) / 4;
		}
		
		void Avrg() {
			cout << name << ',' << age << ',' << Sno << ',' << average_grade << endl;
		}
	};

	Student a;
	a.init();
	a.Avrg();
	return 0;
}