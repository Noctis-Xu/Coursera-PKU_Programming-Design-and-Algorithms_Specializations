#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <string.h> //strlen����

using namespace std;


int Process(char* pc, int number_left, int number_right) {//����ֵ��ʾnumber_right������������pc�ǲ�ͣ��ǰ�ƶ���ָ�룬����ǰָ�룻number_left��ʾ��ƥ����������������������ߺ�ߵ��������Ƿ�ǰ���������ſ�������ƥ�䣻number_right��ʾ��ƥ�����������������������ǰ����������Ƿ�����������ſ�������ƥ��
	int number_right_now;
	while (*pc != '(' && *pc != ')' && *pc != '\0') {//�Ƚ��д�������ĸ��ɿո�
		*pc = ' ';
		pc++;
	}
	char* pc_now = pc;
	if (*pc == '(') {
		number_left++;
		pc++;
		number_right_now = Process(pc, number_left, 0);//ÿ������һ��'('����Ҫ���µ�����������������֮ǰ��ƥ��������Ų���Ӱ�졣���ӣ�"()("
		if (number_right_now > 0) {
			*pc_now = ' ';
			number_right_now--;
		}
		else *pc_now = '$';
		return number_right_now + number_right;//���뷵�����п�ƥ������������������ӣ�"()("����ֹ֮����µĿ�ƥ�������������number_right_now���ǵ�ԭ�еĿ�ƥ�������������number_right
	}
	else if (*pc == ')') {
		if (number_left == 0) {
			*pc_now = '?';
		}
		else if (number_left > 0) {
			*pc_now = ' ';
			number_left--;
			number_right++;
		}
		pc++;
		number_right = Process(pc, number_left, number_right); 
		return number_right;
	}
	else //��*pc == '\0'ʱ�����ݹ�
		return number_right; 
}

int main() {
	size_t len;
	char str[101] = { '\0' };

	while (cin.getline(str, 101)) {
		len = strlen(str);
		cout << str << endl;
		Process(str, 0, 0);
		cout << str << endl;
	}

	return 0;
}