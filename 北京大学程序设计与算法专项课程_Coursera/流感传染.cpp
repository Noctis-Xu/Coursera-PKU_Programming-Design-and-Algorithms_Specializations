#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n;

	//创建二维动态数组
	char** p; //二阶指针，指向char型指针的指针
	p = new char* [n]; //char型指针数组[n]
	for (int i = 0; i < n; i++) {
		p[i] = new char[n]; //char型指针数组中的一阶指针指向char型数组[n]
	}
	//赋初值
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
	cin >> m;

	//process
	char** p_y = new char* [n]; //p_y储存前一天的数据
	for (int i = 0; i < n; i++) {
		p_y[i] = new char[n];
	}

	for (int d = 2; d <= m; d++) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				p_y[u][v] = p[u][v]; //对前一天的数据进行备份，防止在更新今天的数据时丢失前一天的数据
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (p[i][j] == '.' && (j >= 1 && p_y[i][j - 1] == '@' || j < n - 1 && p_y[i][j + 1] == '@' || i >= 1 && p_y[i - 1][j] == '@' || i < n - 1 && p_y[i + 1][j] == '@'))
					p[i][j] = '@';
			}
		}
	}

	int count=0; //统计总患病人数
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i][j] == '@')
				count++;
		}
	}

	//输出
	/*for (int i = 0; i < n; i++) {//输出每一行具体的情况
		for (int j = 0; j < n; j++) {
			cout << p[i][j];
		}
		cout << endl;
	}*/ 
	cout << count; //输出总人数

	for (int i = 0; i < n; i++) {
		delete[] p[i];
		delete[] p_y[i];
	}
	delete[] p;
	delete[] p_y;
	return 0;
}