#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char* reverse(char* pc) {//pc是不停向前移动的指针
	char* pc_temp = pc; //pc_temp表示原有指针的位置
	if (*pc == ' '|| *pc=='\0')
		return pc; //返回当前指针pc的值
	else {
		pc = reverse(++pc);
		cout << *pc_temp;
		return pc; //不停地向前一个函数返回当前指针pc的值
	}
}

int main() {
	char Str[500] = {'\0'};
	char* pc;
	cin.getline(Str, 500);
	for (pc = Str; *pc != '\0';pc++) {//这里*pc != '\0'表示只要Str如果不是空的话就运行。不是判断退出循环的条件
		pc=reverse(pc); //每调用一次，都会输出一个单词（包含其他字符），并且当前指针pc指向' '或'\0'的位置
		if (*pc == ' ')
			cout << ' ';
		else if (*pc == '\0') //真正判断退出循环的条件
			break;
	}
	return 0;
}