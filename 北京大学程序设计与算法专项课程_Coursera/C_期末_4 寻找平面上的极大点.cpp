#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct coordinates {
	int x;
	int y;
};

int main() {
	int n;
	cin >> n;

	coordinates* p = new coordinates[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i].x;
		cin >> p[i].y;
	}
	for (int i = 0; i < n-1; i++) {//按照x坐标从小到大进行冒泡排序
		for (int j = 0; j < n - 1 - i; j++) {
			if (p[j].x > p[j + 1].x) {
				coordinates temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}

	int number=0;//用来记录有多少个极大点
	for (int i = 0; i < n; i++) {
		int flag = 0; //0表示未被其他坐标支配，1表示被其他坐标支配
		for (int j = 0; j < n; j++) {
			if (p[i].x == p[j].x && p[i].y == p[j].y) //跳过自身比较
				continue;
			if (p[i].x <= p[j].x && p[i].y <= p[j].y) //一旦出现被支配的情况，则标记该组坐标
				flag = 1;
		}
		if (flag == 0) {
			number++;
			if (number == 1) {//第一组数据单独输出，因为前面不带','
				printf("(%d,%d)", p[i].x, p[i].y);
			}else
			printf(",(%d,%d)", p[i].x, p[i].y);//未出现被支配的情况，故输出当前极大点
		}
	}

	delete[]p;
	return 0;
}