/*
����
���������������Լ����������������+ - * /��������������

����
��һ�У�������a�����Ȳ�����100
�ڶ��У����������o��o�ǡ�+������-������*������/���е�ĳһ��
�����У�������b�����Ȳ�����100
��֤���벻������Ŀո�������ַ�

���
һ�У����ʽ��a o b����ֵ��
����˵����
1. ��������п���Ϊ����
2. �����������ȡ��
3. ��������ճ���дϰ�ߣ������ж����0���ո�������ַ�

��������
9876543210
+
9876543210

�������
19753086420
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

class BigInt {
public:
	char integer[200] = { '\0' };
	BigInt operator+(const BigInt& b);
	//BigInt operator-(const BigInt& b);
	//BigInt operator*(const BigInt& b);
	//BigInt operator/(const BigInt& b);
	BigInt& operator=(const BigInt& b);
};

BigInt BigInt::operator+(const BigInt& b) {//����һ�������99999+9���᲻�Ͻ�λ
	BigInt c;
	char a_temp[200], b_temp[200];
	char* p_big, * p_small;//p_bigָ��λ���������,p_smallָ��λ���ٵ�����
	strcpy(a_temp, this->integer); strcpy(b_temp, b.integer);
	_strrev(a_temp); _strrev(b_temp);
	int a_size, b_size, size_small, size_big;
	a_size = strlen(a_temp); b_size = strlen(b_temp);
	if (a_size >= b_size) { p_big = a_temp, p_small = b_temp; size_big = a_size; size_small = b_size; }
	else { p_big = b_temp, p_small = a_temp; size_big = b_size; size_small = a_size; }

	int temp_int;//������¼1λ������ӵĽ�����������Ϊ1λ����Ҳ����Ϊ2λ��
	int carry = 0;//��λ
	for (int i = 0; i <= size_big; i++) {
		if (i < size_small) {
			temp_int = carry + (p_big[i] - 48) + (p_small[i] - 48);//temp_int���ֻ����Ϊ��λ��	
		}
		else if (i < size_big) {
			temp_int = carry + (p_big[i] - 48);
		}
		else {
			temp_int = carry;//ע��carry����Ϊ0
			if (temp_int == 0) break;
		}
		carry = 0;

		if (temp_int < 10) {
			c.integer[i] = temp_int + 48;//��48��Ϊ�˰�һλ������ת��Ϊ�ַ�
		}
		else {
			c.integer[i] = temp_int % 10 + 48;//���Ƹ�λ��
			carry = int(temp_int / 10);//��λ
		}
	}
	_strrev(c.integer);
	return c;
}

BigInt& BigInt::operator=(const BigInt& b) {
	strcpy(this->integer, b.integer);
	return *this;
}

istream& operator >> (istream& is, BigInt& c) {
	cin >> c.integer;
	return is;
}
ostream& operator << (ostream& os, BigInt& c) {
	cout << c.integer;
	return os;
}

int main() {
	BigInt a, b, c;
	char operation;
	cin >> a >> operation >> b;
	switch (operation) {
	case '+':c = a + b; break;
		//case '-':c = a - b; break;
		//case '*':c = a * b; break;
		//case '/':c = a / b; break;
	}
	cout << c << endl;

	return 0;
}