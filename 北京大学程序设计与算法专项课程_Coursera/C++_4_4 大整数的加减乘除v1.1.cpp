//v1.1版本编写了自己的strrev

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

	BigInt() {}//默认构造函数
	BigInt(const BigInt& a) {//复制构造函数，用来初始化语句
		strcpy(this->integer, a.integer);
	}
	//BigInt(const int a) {//复制构造函数，用来初始化语句
	//	itoa(a, this->integer, 10);
	//}

};

BigInt BigInt::operator+(const BigInt& b) {//考虑一种情况，99999+9，会不断进位
	BigInt c;
	char a_temp[201], b_temp[201];
	char* p_big, * p_small;//p_big指向位数多的整数,p_small指向位数少的整数
	strcpy(a_temp, this->integer); strcpy(b_temp, b.integer);
	strrev_(a_temp); strrev_(b_temp);
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
	strrev_(c.integer);
	return c;
}

BigInt BigInt::operator-(const BigInt& b) {//这里不包括负整数的减法，所以-12313-123123以及-123123--123123是没法计算的
	BigInt c;
	char a_temp[201], b_temp[201];//a是被减数
	char* p_big, * p_small;//p_big指向位数多的整数,p_small指向位数少的整数
	int a_size, b_size, size_small, size_big;
	strcpy(a_temp, this->integer); strcpy(b_temp, b.integer);
	a_size = strlen(a_temp); b_size = strlen(b_temp);


	//首先要判断a是否大于等于b，如果a<b，则结果为负数，需要用b减a再加上符号位'-'。
	//分为5种情况：a_size=b_size且2个数字完全一样，结果为0；a_size=b_size但a>b,结果为正；a_size=b_size但a<b,结果为负；a_size>b_size，结果为正；a_size<b_size，结果为负
	bool IsNegative = false;//结果是否为负数
	if (a_size == b_size) {
		if (strcmp(a_temp, b_temp) == 0) { c.integer[0] = '0'; return c; }//a=b，所以相减结果为0，直接返回
		else if (strcmp(a_temp, b_temp) < 0) {//a_size=b_size但a<b，结果为负
			IsNegative = true;
			p_big = b_temp, p_small = a_temp; size_big = b_size; size_small = a_size;
		}
		else {//a_size=b_size但a>b，结果为正
			p_big = a_temp; p_small = b_temp; size_big = a_size; size_small = b_size;
		}
	}
	else if (a_size < b_size) {//a_size<b_size，结果为负
		IsNegative = true;
		p_big = b_temp, p_small = a_temp; size_big = b_size; size_small = a_size;
	}
	else {//a_size>b_size，结果为正
		p_big = a_temp; p_small = b_temp; size_big = a_size; size_small = b_size;
	}

	//模拟减法过程
	strrev_(a_temp); strrev_(b_temp);//翻转，字符串从左到右为个位数，十位数，百位数...
	int borrow = 0;//借位，只可能为0或1
	for (int i = 0; i < size_big; i++) {//结果不会超过最大的数
		if (i < size_small) {
			if (p_big[i] >= p_small[i] + borrow) {//不用借位
				c.integer[i] = (p_big[i] - p_small[i] - borrow) + 48;//这里是2个字符串相减，抵掉了48。括号里是数字，+48转字符
				borrow = 0;
			}
			else {
				c.integer[i] = (10 + p_big[i] - p_small[i] - borrow) + 48;
				borrow = 1;
			}
		}
		else {
			if (p_big[i] - 48 >= borrow) {//最高位至少为1，如数字1000，所以肯定执行这条if语句而不是else语句
				c.integer[i] = (p_big[i] - 48 - borrow) + 48;//括号里是数字，-48是为了字符转数字
				borrow = 0;
			}
			else {
				c.integer[i] = (10 + p_big[i] - 48 - borrow) + 48;
				borrow = 1;
			}
		}
	}
	for (int i = size_big - 1; i >= 0; i--) {//10-9=1而不是01，1001-1000=1而不是0001。要注意结果为0的情况在这里不会出现，因为a=b的情况在for循环上面已经讨论过
		if (c.integer[i] == '0') { c.integer[i] = '\0'; }
		else {//遇到第一个高位不为0的情况时
			if (IsNegative) { c.integer[i + 1] = '-'; }//负数把符号位加上
			break;
		}
	}

	strrev_(c.integer);
	return c;
}


/*
				889
			*     9
——————————————————————
carry_mul	   7780
standard		221
carry_add      1100
——————————————————————
			   8001
*/
char* OneDigitMultiply(char* a, char b, char* c) {//大整数a与一位数b的乘法，a和返回值product都是从左到右为低位到高位。c用来保存product的值
	char product[201];//保存结果。100位与100位相乘，结果一定小于等于200位
	int carry_mul = 0;//乘法进位
	int carry_add = 0;//加法进位
	int standard;//本位
	int temp_product;
	int a_size = strlen(a);
	if (b == '0') {//乘数为0的情况
		product[0] = '0';
		product[1] = '\0';
		strcpy(c, product);
		return 0;
	}
	else {
		for (int i = 0; i < a_size; i++) {
			temp_product = (a[i] - 48) * (b - 48);//本位相乘的乘积
			standard = temp_product % 10;
			product[i] = (standard + carry_add + carry_mul) % 10 + 48;//当前计算
			carry_add = (standard + carry_add + carry_mul) / 10;//为下一位做准备
			carry_mul = temp_product / 10;//为下一位做准备
		}
		if (carry_add + carry_mul != 0) {
			product[a_size] = carry_add + carry_mul + 48;//最高位没有standard，单独拿出来计算，如889*9=8001中的8。但要注意如果carry_add和carry_mul=0，比如111*9的情况，那么结果应该是999而不是0999
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
	char* p_big, * p_small;//p_big指向位数多的整数,p_small指向位数少的整数
	a_size = strlen(a_temp); b_size = strlen(b_temp);
	if (a_size >= b_size) { p_big = a_temp, p_small = b_temp; size_big = a_size; size_small = b_size; }
	else { p_big = b_temp, p_small = a_temp; size_big = b_size; size_small = a_size; }


	c.integer[0] = '0';
	for (int i = 0; i < size_small; i++) {//大数放上面，小数放下面，乘的次数即为小数的位数，相加的次数也是小数的位数
		BigInt d;
		OneDigitMultiply(p_big, p_small[i], d.integer);
		strrev_(d.integer);//从左到右为从高位到低位
		int size_d = strlen(d.integer);
		if (d.integer[0] != '0') {
			for (int j = 0; j < i; j++) {//低位最后补0,i=0在最后补0个0，i=1补1个0，i=2补2个0
				d.integer[size_d + j] = '0';
			}
		}
		c = c + d;//正序，从左到右为高位到低位
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

//大整数除法思路见网址：http://ddrv.cn/a/80907
BigInt BigInt::operator/(const BigInt& b) {//除法结果最大为100位
	//注意！这里定义了静态局部变量，只在第一次执行该函数时赋值。所以在main函数里也只能计算一次a/b。因为第二次计算a/b时再调用这个函数不会再初始化静态变量，里面的值还是第一次a/b时留下来的值
	static BigInt c;//用来存放除法结果商
	static BigInt remainder = *this;//余数。最开始余数就等于被除数
	static int b_size = strlen(b.integer);//除数的位数

	if (b.integer[0] == '0') { //除数为0的情况
		cout << "error" << endl;
		return c;
	}
	else if (remainder < b) {//余数小于除数时
		if (c.integer[0] == '\0') {//如果第一次调用该函数时就执行了该语句，则说明被除数小于除数，比如1/20，则c=0
			c.integer[0] = '0';
		}
		strrev_(c.integer);
		return c;
	}
	else {
		int rmd_size = strlen(remainder.integer);
		int difference_size = rmd_size - b_size;//被除数与除数位数的差别。因为在这个else语句里remainder>=b, 所以remainder的位数>=b, difference_size>=0
		BigInt subtrahend = b;//减数
		for (int i = 0; i < difference_size; i++) {//减数扩充位数。例如1998/23，先把23扩充为2300
			subtrahend.integer[b_size + i] = '0';
		}
		int j = 0;//用来保存商，不计倍数（即不计0）
		if (subtrahend <= remainder) {//例如2400/23，把23扩充为2300后，2300<=2400，可以执行该语句
			for (; j < 9; j++) {//最多减9次
				if (subtrahend <= remainder) {//减数比余数小，则可以减。注意！！！不要写成subtrahend -remainder <= 0，因为如果subtrahend -remainder减出来是负数，那么在调用运算符重载函数<=时，会进行负数-0的运算，但是这里的大整数减法没有定义负整数的减法，所以会运行错误
					remainder = remainder - subtrahend;
				}
				else break;
			}
			if (j > 0) {//说明remainder有被减过
				for (int i = 0; i < difference_size; i++) {//这里的c.integer从左往右为从低位到高位，如001表示商为100
					c.integer[i] = '0';
				}
				c.integer[difference_size] = j + 48;
			}
		}
		else {//1998/23，把23扩充为2300后，2300>1998，没法减，所以把2300改为为230再减
			difference_size--;
			subtrahend.integer[b_size + difference_size] = '\0';//2300改为230
			if (subtrahend <= remainder) {//例如2400/23，把23扩充为2300后，2300<=2400，可以执行该语句
				for (; j < 9; j++) {//最多减9次
					if (subtrahend <= remainder) {//减数比余数小，则可以减
						remainder = remainder - subtrahend;
					}
					else break;
				}
				if (j > 0) {//说明remainder有被减过
					for (int i = 0; i < difference_size; i++) {//这里的c.integer从左往右为从低位到高位，如001表示商为100
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