#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char* reverse(char* pc) {//pc�ǲ�ͣ��ǰ�ƶ���ָ��
	char* pc_temp = pc; //pc_temp��ʾԭ��ָ���λ��
	if (*pc == ' '|| *pc=='\0')
		return pc; //���ص�ǰָ��pc��ֵ
	else {
		pc = reverse(++pc);
		cout << *pc_temp;
		return pc; //��ͣ����ǰһ���������ص�ǰָ��pc��ֵ
	}
}

int main() {
	char Str[500] = {'\0'};
	char* pc;
	cin.getline(Str, 500);
	for (pc = Str; *pc != '\0';pc++) {//����*pc != '\0'��ʾֻҪStr������ǿյĻ������С������ж��˳�ѭ��������
		pc=reverse(pc); //ÿ����һ�Σ��������һ�����ʣ����������ַ��������ҵ�ǰָ��pcָ��' '��'\0'��λ��
		if (*pc == ' ')
			cout << ' ';
		else if (*pc == '\0') //�����ж��˳�ѭ��������
			break;
	}
	return 0;
}