//v1.1�汾��д���Լ���strrev

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
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <string>
#include <string.h>
using namespace std;

char* strrev_(char* s)
{
	if (s == NULL || s[0] == '\0')
		return s;

	for (char t, *p = s, *q = s + strlen(s) - 1; p < q; p++, q--)
		t = *p, * p = *q, * q = t;

	return s;
}

class BigInt {
public:
	char integer[201] = { '\0' };
	BigInt operator+(const BigInt& b);
	BigInt operator-(const BigInt& b);
	BigInt operator*(const BigInt& b);
	BigInt operator/(const BigInt& b);
	BigInt& operator=(const BigInt& b);
	bool operator<(const BigInt b);
	bool operator<=(const BigInt b);

	BigInt() {}//Ĭ�Ϲ��캯��
	BigInt(const BigInt& a) {//���ƹ��캯����������ʼ�����
		strcpy(this->integer, a.integer);
	}
	//BigInt(const int a) {//���ƹ��캯����������ʼ�����
	//	itoa(a, this->integer, 10);
	//}

};

BigInt BigInt::operator+(const BigInt& b) {//����һ�������99999+9���᲻�Ͻ�λ
	BigInt c;
	char a_temp[201], b_temp[201];
	char* p_big, * p_small;//p_bigָ��λ���������,p_smallָ��λ���ٵ�����
	strcpy(a_temp, this->integer); strcpy(b_temp, b.integer);
	strrev_(a_temp); strrev_(b_temp);
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
	strrev_(c.integer);
	return c;
}

BigInt BigInt::operator-(const BigInt& b) {//���ﲻ�����������ļ���������-12313-123123�Լ�-123123--123123��û�������
	BigInt c;
	char a_temp[201], b_temp[201];//a�Ǳ�����
	char* p_big, * p_small;//p_bigָ��λ���������,p_smallָ��λ���ٵ�����
	int a_size, b_size, size_small, size_big;
	strcpy(a_temp, this->integer); strcpy(b_temp, b.integer);
	a_size = strlen(a_temp); b_size = strlen(b_temp);


	//����Ҫ�ж�a�Ƿ���ڵ���b�����a<b������Ϊ��������Ҫ��b��a�ټ��Ϸ���λ'-'��
	//��Ϊ5�������a_size=b_size��2��������ȫһ�������Ϊ0��a_size=b_size��a>b,���Ϊ����a_size=b_size��a<b,���Ϊ����a_size>b_size�����Ϊ����a_size<b_size�����Ϊ��
	bool IsNegative = false;//����Ƿ�Ϊ����
	if (a_size == b_size) {
		if (strcmp(a_temp, b_temp) == 0) { c.integer[0] = '0'; return c; }//a=b������������Ϊ0��ֱ�ӷ���
		else if (strcmp(a_temp, b_temp) < 0) {//a_size=b_size��a<b�����Ϊ��
			IsNegative = true;
			p_big = b_temp, p_small = a_temp; size_big = b_size; size_small = a_size;
		}
		else {//a_size=b_size��a>b�����Ϊ��
			p_big = a_temp; p_small = b_temp; size_big = a_size; size_small = b_size;
		}
	}
	else if (a_size < b_size) {//a_size<b_size�����Ϊ��
		IsNegative = true;
		p_big = b_temp, p_small = a_temp; size_big = b_size; size_small = a_size;
	}
	else {//a_size>b_size�����Ϊ��
		p_big = a_temp; p_small = b_temp; size_big = a_size; size_small = b_size;
	}

	//ģ���������
	strrev_(a_temp); strrev_(b_temp);//��ת���ַ���������Ϊ��λ����ʮλ������λ��...
	int borrow = 0;//��λ��ֻ����Ϊ0��1
	for (int i = 0; i < size_big; i++) {//������ᳬ��������
		if (i < size_small) {
			if (p_big[i] >= p_small[i] + borrow) {//���ý�λ
				c.integer[i] = (p_big[i] - p_small[i] - borrow) + 48;//������2���ַ���������ֵ���48�������������֣�+48ת�ַ�
				borrow = 0;
			}
			else {
				c.integer[i] = (10 + p_big[i] - p_small[i] - borrow) + 48;
				borrow = 1;
			}
		}
		else {
			if (p_big[i] - 48 >= borrow) {//���λ����Ϊ1��������1000�����Կ϶�ִ������if��������else���
				c.integer[i] = (p_big[i] - 48 - borrow) + 48;//�����������֣�-48��Ϊ���ַ�ת����
				borrow = 0;
			}
			else {
				c.integer[i] = (10 + p_big[i] - 48 - borrow) + 48;
				borrow = 1;
			}
		}
	}
	for (int i = size_big - 1; i >= 0; i--) {//10-9=1������01��1001-1000=1������0001��Ҫע����Ϊ0����������ﲻ����֣���Ϊa=b�������forѭ�������Ѿ����۹�
		if (c.integer[i] == '0') { c.integer[i] = '\0'; }
		else {//������һ����λ��Ϊ0�����ʱ
			if (IsNegative) { c.integer[i + 1] = '-'; }//�����ѷ���λ����
			break;
		}
	}

	strrev_(c.integer);
	return c;
}


/*
				889
			*     9
��������������������������������������������
carry_mul	   7780
standard		221
carry_add      1100
��������������������������������������������
			   8001
*/
char* OneDigitMultiply(char* a, char b, char* c) {//������a��һλ��b�ĳ˷���a�ͷ���ֵproduct���Ǵ�����Ϊ��λ����λ��c��������product��ֵ
	char product[201];//��������100λ��100λ��ˣ����һ��С�ڵ���200λ
	int carry_mul = 0;//�˷���λ
	int carry_add = 0;//�ӷ���λ
	int standard;//��λ
	int temp_product;
	int a_size = strlen(a);
	if (b == '0') {//����Ϊ0�����
		product[0] = '0';
		product[1] = '\0';
		strcpy(c, product);
		return 0;
	}
	else {
		for (int i = 0; i < a_size; i++) {
			temp_product = (a[i] - 48) * (b - 48);//��λ��˵ĳ˻�
			standard = temp_product % 10;
			product[i] = (standard + carry_add + carry_mul) % 10 + 48;//��ǰ����
			carry_add = (standard + carry_add + carry_mul) / 10;//Ϊ��һλ��׼��
			carry_mul = temp_product / 10;//Ϊ��һλ��׼��
		}
		if (carry_add + carry_mul != 0) {
			product[a_size] = carry_add + carry_mul + 48;//���λû��standard�������ó������㣬��889*9=8001�е�8����Ҫע�����carry_add��carry_mul=0������111*9���������ô���Ӧ����999������0999
			product[a_size + 1] = '\0';
		}
		else {
			product[a_size] = '\0';
		}
		strcpy(c, product);
		return 0;
	}
}

BigInt BigInt::operator*(const BigInt& b) {
	BigInt c;
	char a_temp[201], b_temp[201];
	strcpy(a_temp, this->integer); strcpy(b_temp, b.integer);
	strrev_(a_temp); strrev_(b_temp);
	int a_size, b_size, size_small, size_big;
	char* p_big, * p_small;//p_bigָ��λ���������,p_smallָ��λ���ٵ�����
	a_size = strlen(a_temp); b_size = strlen(b_temp);
	if (a_size >= b_size) { p_big = a_temp, p_small = b_temp; size_big = a_size; size_small = b_size; }
	else { p_big = b_temp, p_small = a_temp; size_big = b_size; size_small = a_size; }


	c.integer[0] = '0';
	for (int i = 0; i < size_small; i++) {//���������棬С�������棬�˵Ĵ�����ΪС����λ������ӵĴ���Ҳ��С����λ��
		BigInt d;
		OneDigitMultiply(p_big, p_small[i], d.integer);
		strrev_(d.integer);//������Ϊ�Ӹ�λ����λ
		int size_d = strlen(d.integer);
		if (d.integer[0] != '0') {
			for (int j = 0; j < i; j++) {//��λ���0,i=0�����0��0��i=1��1��0��i=2��2��0
				d.integer[size_d + j] = '0';
			}
		}
		c = c + d;//���򣬴�����Ϊ��λ����λ
	}
	return c;
}

bool BigInt::operator<(const BigInt b) {
	BigInt c;
	c = *this - b;
	if (c.integer[0] == '-') {
		return true;
	}
	else return false;
}

bool BigInt::operator<=(const BigInt b) {
	BigInt c;
	c = *this - b;
	if (c.integer[0] == '-' || c.integer[0] == '0') {
		return true;
	}
	else return false;
}

//����������˼·����ַ��http://ddrv.cn/a/80907
BigInt BigInt::operator/(const BigInt& b) {//����������Ϊ100λ
	//ע�⣡���ﶨ���˾�̬�ֲ�������ֻ�ڵ�һ��ִ�иú���ʱ��ֵ��������main������Ҳֻ�ܼ���һ��a/b����Ϊ�ڶ��μ���a/bʱ�ٵ���������������ٳ�ʼ����̬�����������ֵ���ǵ�һ��a/bʱ��������ֵ
	static BigInt c;//������ų��������
	static BigInt remainder = *this;//�������ʼ�����͵��ڱ�����
	static int b_size = strlen(b.integer);//������λ��

	if (b.integer[0] == '0') { //����Ϊ0�����
		cout << "error" << endl;
		return c;
	}
	else if (remainder < b) {//����С�ڳ���ʱ
		if (c.integer[0] == '\0') {//�����һ�ε��øú���ʱ��ִ���˸���䣬��˵��������С�ڳ���������1/20����c=0
			c.integer[0] = '0';
		}
		strrev_(c.integer);
		return c;
	}
	else {
		int rmd_size = strlen(remainder.integer);
		int difference_size = rmd_size - b_size;//�����������λ���Ĳ����Ϊ�����else�����remainder>=b, ����remainder��λ��>=b, difference_size>=0
		BigInt subtrahend = b;//����
		for (int i = 0; i < difference_size; i++) {//��������λ��������1998/23���Ȱ�23����Ϊ2300
			subtrahend.integer[b_size + i] = '0';
		}
		int j = 0;//���������̣����Ʊ�����������0��
		if (subtrahend <= remainder) {//����2400/23����23����Ϊ2300��2300<=2400������ִ�и����
			for (; j < 9; j++) {//����9��
				if (subtrahend <= remainder) {//����������С������Լ���ע�⣡������Ҫд��subtrahend -remainder <= 0����Ϊ���subtrahend -remainder�������Ǹ�������ô�ڵ�����������غ���<=ʱ������и���-0�����㣬��������Ĵ���������û�ж��帺�����ļ��������Ի����д���
					remainder = remainder - subtrahend;
				}
				else break;
			}
			if (j > 0) {//˵��remainder�б�����
				for (int i = 0; i < difference_size; i++) {//�����c.integer��������Ϊ�ӵ�λ����λ����001��ʾ��Ϊ100
					c.integer[i] = '0';
				}
				c.integer[difference_size] = j + 48;
			}
		}
		else {//1998/23����23����Ϊ2300��2300>1998��û���������԰�2300��ΪΪ230�ټ�
			difference_size--;
			subtrahend.integer[b_size + difference_size] = '\0';//2300��Ϊ230
			if (subtrahend <= remainder) {//����2400/23����23����Ϊ2300��2300<=2400������ִ�и����
				for (; j < 9; j++) {//����9��
					if (subtrahend <= remainder) {//����������С������Լ�
						remainder = remainder - subtrahend;
					}
					else break;
				}
				if (j > 0) {//˵��remainder�б�����
					for (int i = 0; i < difference_size; i++) {//�����c.integer��������Ϊ�ӵ�λ����λ����001��ʾ��Ϊ100
						c.integer[i] = '0';
					}
					c.integer[difference_size] = j + 48;
				}
			}
		}
		c = remainder / b;
		return c;
	}
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
	case '-':c = a - b; break;
	case '*':c = a * b; break;
	case '/':c = a / b; break;
	}
	cout << c << endl;

	return 0;
}