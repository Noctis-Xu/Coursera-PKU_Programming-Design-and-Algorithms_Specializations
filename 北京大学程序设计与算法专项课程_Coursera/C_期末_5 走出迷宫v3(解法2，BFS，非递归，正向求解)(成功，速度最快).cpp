/*不用递归，正向求解，用BFS思路。速度极快*/

/*思路
在开始循环前先把S置为#
从S开始，直到找到T结束循环(用flag标记是否找到T，找到T则flag为true，否则为假)
1.第一次循环：
①首先判断左上右下4个方向哪个方向下一步可以走（不能是边界而且是'.'或者T）
②然后判断所有可以走的下一步是不是T，是的话flag=true，结束循环；不是的话把下一步可以走的点都置为#，并用数组p_ready记录下一步可以走的点
③steps++
2.第二次循环：对数组中的每个元素再进行第1步操作，然后用一个新的数组记录下一步可以走的点，注意记录前对之前的数组元素清空
3.第三次循环：对新的数组中的每个元素再进行上述第1步操作，然后用一个新的数组记录下一步可以走的点
可以把S先放入p_ready当中，这样第1步与第2步和第三步可以放在同一个循环下
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include "time.h"//测试运行时间

#define p_ready_amount 200

using namespace std;
int n, m;

struct {
	int r = -1;//行
	int c = -1;//列
}p_ready[p_ready_amount],p_ready_temp[p_ready_amount];//p_ready_temp用来临时记录新产生的下一步可走的点

int main() {
	cin >> n >> m;
	char** p = new char* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new char[m];
	}
	int S_n, S_m;//入口的行和列
	for (int i = 0; i < n; i++) {//给迷宫赋值
		for (int j = 0; j < m; j++) {
			cin >> p[i][j];
			if (p[i][j] == 'S') { //找到入口
				S_n = i;
				S_m = j;
			}
		}
	}

	//clock_t start_time, end_time;
	//start_time = clock();   //获取开始执行时间

	p_ready[0].r = S_n;
	p_ready[0].c = S_m;
	p_ready_temp[0].r = S_n;
	p_ready_temp[0].c = S_m;
	p[p_ready[0].r][p_ready[0].c] = '#';
	int steps = 0;
	bool flag = false;
	while (flag == false) {
		for (int t = 0; t < p_ready_amount; t++) {
			p_ready[t] = p_ready_temp[t];
		}
		int j = 0;
		for (int i = 0; p_ready[i].r != -1; i++) {//对p_ready数组中的每个元素进行遍历，-1表示封尾
			if (p_ready[i].c > 0 && p[p_ready[i].r][p_ready[i].c - 1] != '#') {//判断下一步是否可以左移
				if (p[p_ready[i].r][p_ready[i].c - 1] == 'T') {//到达终点
					flag = true;
					break;
				}
				else {
					p[p_ready[i].r][p_ready[i].c - 1] = '#';
					p_ready_temp[j].r = p_ready[i].r;
					p_ready_temp[j].c = p_ready[i].c - 1;
					j++;
				}				
			}
			if (p_ready[i].r > 0 && p[p_ready[i].r - 1][p_ready[i].c] != '#') {//上移
				if (p[p_ready[i].r - 1][p_ready[i].c] == 'T') {
					flag = true;
					break;
				}
				else {
					p[p_ready[i].r - 1][p_ready[i].c] = '#';
					p_ready_temp[j].r = p_ready[i].r-1;
					p_ready_temp[j].c = p_ready[i].c;
					j++;
				}
				
			}
			if (p_ready[i].c < m - 1 && p[p_ready[i].r][p_ready[i].c + 1] != '#') {//右移
				if (p[p_ready[i].r][p_ready[i].c + 1] == 'T') {
					flag = true;
					break;
				}
				else {
					p[p_ready[i].r][p_ready[i].c + 1] = '#';
					p_ready_temp[j].r = p_ready[i].r;
					p_ready_temp[j].c = p_ready[i].c + 1;
					j++;
				}
			
			}
			if (p_ready[i].r < n - 1 && p[p_ready[i].r + 1][p_ready[i].c] != '#') {//下移
				if (p[p_ready[i].r + 1][p_ready[i].c] == 'T') {
					flag = true;
					break;
				}
				else {
					p[p_ready[i].r + 1][p_ready[i].c] = '#';
					p_ready_temp[j].r = p_ready[i].r+1;
					p_ready_temp[j].c = p_ready[i].c;
					j++;
				}
			}
		}
		steps++;
		p_ready_temp[j].r = -1;//封尾
	}

	cout << steps << endl;


	for (int i = 0; i < n; i++) {
		delete[]p[i];
	}
	delete[]p;

	//end_time = clock();     //获取结束时间
	//double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	//printf("%f seconds\n", Times);

	return 0;
}