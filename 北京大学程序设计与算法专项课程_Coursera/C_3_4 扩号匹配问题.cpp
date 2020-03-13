#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <string.h> //strlen函数

using namespace std;


int Process(char* pc, int number_left, int number_right) {//函数值表示number_right右括号数量；pc是不停向前移动的指针，即当前指针；number_left表示可匹配的左括号数量，用来告诉后边的右括号是否前面有左括号可以拿来匹配；number_right表示可匹配的右括号数量，用来告诉前面的左括号是否后面有右括号可以拿来匹配
	int number_right_now;
	while (*pc != '(' && *pc != ')' && *pc != '\0') {//先进行处理，把字母变成空格
		*pc = ' ';
		pc++;
	}
	char* pc_now = pc;
	if (*pc == '(') {
		number_left++;
		pc++;
		number_right_now = Process(pc, number_left, 0);//每次遇到一个'('，都要用新的右括号数量，避免之前可匹配的右括号产生影响。例子："()("
		if (number_right_now > 0) {
			*pc_now = ' ';
			number_right_now--;
		}
		else *pc_now = '$';
		return number_right_now + number_right;//必须返回所有可匹配的右括号数量，例子："()("。防止之后的新的可匹配的右括号数量number_right_now覆盖掉原有的可匹配的右括号数量number_right
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
	else //当*pc == '\0'时结束递归
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