#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Ch_Num {
	char character[5]="\0";
	int number = 0;//��ʾĳһ��ĸһ���м���
	int successive_number=501;//��ʾĳһ��ĸ���ַ����еġ��ڼ�����λ�õ�һ�γ���
	int flag=0;//��Ǹ���ĸ�Ƿ��һ�γ��֣��������Ϊ0��������Ϊ1
};

int main() {
	Ch_Num alphabet[26];
	char str[501];
	cin >> str;

	for (int i = 0; i < 26; i++) {
		alphabet[i].character[0] = char(65 + i);//��д��ĸ
		alphabet[i].character[1] = '+';
		alphabet[i].character[2] = char(65 + i + 32);//Сд��ĸ
		alphabet[i].character[3] = ':';
		alphabet[i].character[4] = '\0';
	}

	for (int i = 0; str[i] != '\0'; i++) {
		for (int j = 0; j < 26; j++) {
			if (str[i] == 'A' + j || str[i] == 'A' + j + 32) {
				alphabet[j].number++;
				if (alphabet[j].flag == 0) {
					alphabet[j].successive_number = i;
					alphabet[j].flag = 1;
				}
			}
		}
	}

	for (int i = 0; i < 25; i++) {//ð������
		for (int j = 0; j < 25 - i; j++) {
			if (alphabet[j].number < alphabet[j + 1].number) {
				Ch_Num temp = alphabet[j];
				alphabet[j] = alphabet[j + 1];
				alphabet[j + 1] = temp;
			}
		}
	}

	int max = alphabet[0].number;
	int second_max=0;
	for(int i = 1; i < 26; i++){//�ҳ��ڶ���Ĵ���
		if (alphabet[i].number < max) {
			second_max = alphabet[i].number;
			break;
		}
	}

	Ch_Num second_alphabet[26];//�����ڶ����������ĸ
	for (int i = 0; i < 26; i++) {//�ҳ������ڶ����������ĸ
		if (alphabet[i].number == second_max) {
			second_alphabet[i] = alphabet[i];
		}
	}

	for (int i = 0; i < 25; i++) {//�Դ����ڶ������ĸ�������������׼Ϊ���ֵ�λ�ã�λ����ǰ�ķ�ǰ��
		for (int j = 0; j < 25 - i; j++) {
			if (second_alphabet[j].successive_number > second_alphabet[j + 1].successive_number) {
				Ch_Num temp = second_alphabet[j];
				second_alphabet[j] = second_alphabet[j + 1];
				second_alphabet[j + 1] = temp;
			}
		}
	}

	cout << second_alphabet[0].character << second_alphabet[0].number << endl;

	return 0;
}