#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <string.h> //strlen����

using namespace std;

char Str[101] = { '\0' };
size_t len;
char A, B;

const char* Process(const char* pc) { //pc�ǲ�ͣ��ǰ�ƶ���ָ�룬����ǰָ��
	const char* pc_now = pc; //pc_now��Ŀǰ�ַ�A������λ��
	if (*(pc + 1) == '\0')
		return NULL;
	else if (*(pc + 1) == B) {
		printf("%d %d\n", int((pc_now - Str) / sizeof(char)), int((pc + 1 - Str) / sizeof(char)));
		//cout << (pc_now - Str) / sizeof(char) << ' ' << (pc + 1 - Str) / sizeof(char) << endl; //coursera�ϱ��벻ͨ��
		return pc + 1;
	}
	else {

		while (*(pc + 1) != B) {
			pc++;
			pc = Process(pc);
		}
		printf("%d %d\n", int((pc_now - Str) / sizeof(char)), int((pc + 1 - Str) / sizeof(char)));
		//cout << (pc_now - Str) / sizeof(char) << ' ' << (pc + 1 - Str) / sizeof(char) << endl;
		return pc + 1;
	}
}

int main() {
	char* pc = Str;
	cin.getline(Str, 101);
	len = strlen(Str);
	A = Str[0], B = Str[len - 1];
	Process(Str);
	return 0;
}