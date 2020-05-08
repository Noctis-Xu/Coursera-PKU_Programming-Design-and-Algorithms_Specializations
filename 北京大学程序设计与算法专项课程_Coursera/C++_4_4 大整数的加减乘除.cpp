/*
描述
给出两个正整数以及四则运算操作符（+ - * /），求运算结果。

输入
第一行：正整数a，长度不超过100
第二行：四则运算符o，o是“+”，“-”，“*”，“/”中的某一个
第三行：正整数b，长度不超过100
保证输入不含多余的空格或其它字符

输出
一行：表达式“a o b”的值。
补充说明：
1. 减法结果有可能为负数
2. 除法结果向下取整
3. 输出符合日常书写习惯，不能有多余的0、空格或其它字符

样例输入
9876543210
+
9876543210

样例输出
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

BigInt BigInt::operator+(const BigInt& b) {//考虑一种情况，99999+9，会不断进位
	BigInt c;
	char a_temp[200], b_temp[200];
	char* p_big, * p_small;//p_big指向位数多的整数,p_small指向位数少的整数
	strcpy(a_temp, this->integer); strcpy(b_temp, b.integer);
	_strrev(a_temp); _strrev(b_temp);
	int a_size, b_size, size_small, size_big;
	a_size = strlen(a_temp); b_size = strlen(b_temp);
	if (a_size >= b_size) { p_big = a_temp, p_small = b_temp; size_big = a_size; size_small = b_size; }
	else { p_big = b_temp, p_small = a_temp; size_big = b_size; size_small = a_size; }

	int temp_int;//用来记录1位整数相加的结果，结果可能为1位数，也可能为2位数
	int carry = 0;//进位
	for (int i = 0; i <= size_big; i++) {
		if (i < size_small) {
			temp_int = carry + (p_big[i] - 48) + (p_small[i] - 48);//temp_int最大只可能为两位数	
		}
		else if (i < size_big) {
			temp_int = carry + (p_big[i] - 48);
		}
		else {
			temp_int = carry;//注意carry可能为0
			if (temp_int == 0) break;
		}
		carry = 0;

		if (temp_int < 10) {
			c.integer[i] = temp_int + 48;//加48是为了把一位数整数转换为字符
		}
		else {
			c.integer[i] = temp_int % 10 + 48;//复制个位数
			carry = int(temp_int / 10);//进位
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