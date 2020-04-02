/*
要点：
1.不能走走过的路，否则会陷入死循环。比如二格反复、四格正方形路线、矩形路线。本程序解决方案把走过的路线设为障碍物（墙壁'#')
2.函数入口要传入前一次的位置，对于第一次来说则是传入入口S
3.每次递归返回最短路径
4.判断边界
5.判断墙壁
6.优化性能1：对同一点只计算一次到出口的最短路径。迷宫的走法只和当前位置有关，所以很多计算结果是可以重复利用。对于100*100的迷宫，一共10000个点，递归函数只需要被调用10000，重复对一个点的计算是可以避免的。
7.优化性能2：如果当前走的路线将要超过已知的最短路线步数，则停止
*/

/*问题：速度太慢，稍微大一点的数组就要等待很长时间*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int n, m;//迷宫n行m列
int shortest_steps;

int min(int a, int b) {
	if (a == -1 && b == -1) {
		return -1;
	}
	else if (a == -1 && b != -1) {
		return b;
	}
	else if (a != -1 && b == -1) {
		return a;
	}
	else if (a >= b) {
		return b;
	}
	else return a;
}

//int recursion(char* p[], int r, int c, int move = 0) {//p表示数组；r,c表示这次的位置，r为行，c为列，对应要求中的第2点；move表示移动的轨迹，move为0表示不动，1表示上一步进行了左移，2为上移，3为右移，4为下移
//	int steps_left = -1, steps_up = -1, steps_right = -1, steps_down = -1;//分别表示左上右下各自移动的步数，取最小值返回，至少为1。对应要求中的第3点
//	int min(int a, int b);//声明函数
//	char** p_temp=p;
//	if (c > 0 && move != 3 && p[r][c - 1] != '#') {//进行左移，前提是不在第一列以及上一步没有进行右移。对应要求中的1，4和5
//		if (p[r][c - 1] == 'T') {//到达终点
//			return 1;
//		}
//		else {
//			for (int i = 0; i < n; i++) {//生成一个新的迷宫，该迷宫把走过的路设为墙壁，防止走回头路，对应要点6
//				for (int j = 0; j < m; j++) {
//					p_temp[i][j] = p[i][j];
//				}
//			}
//			p_temp[r][c - 1] = '#';
//			steps_left = recursion(p_temp, r, c - 1, 1);
//			steps_left++;//因为当前操作左移也消耗了一步
//		}
//	}
//	if (r > 0 && move != 4 && p[r - 1][c] != '#') {//上移
//		if (p[r - 1][c] == 'T') {
//			return 1;
//		}
//		else {
//			for (int i = 0; i < n; i++) {//生成一个新的迷宫，该迷宫把走过的路设为墙壁，防止走回头路，对应要点6
//				for (int j = 0; j < m; j++) {
//					p_temp[i][j] = p[i][j];
//				}
//			}
//			p_temp[r-1][c] = '#';
//			steps_up = recursion(p, r - 1, c, 2);
//			steps_up++;
//		}
//	}
//	if (c < m - 1 && move != 1 && p[r][c + 1] != '#') {//右移
//		if (p[r][c + 1] == 'T') {
//			return 1;
//		}
//		else {
//			for (int i = 0; i < n; i++) {//生成一个新的迷宫，该迷宫把走过的路设为墙壁，防止走回头路，对应要点6
//				for (int j = 0; j < m; j++) {
//					p_temp[i][j] = p[i][j];
//				}
//			}
//			p_temp[r][c+1] = '#';
//			steps_right = recursion(p, r, c + 1, 3);
//			steps_right++;
//		}
//	}
//	if (r < n - 1 && move != 2 && p[r + 1][c] != '#') {//下移
//		if (p[r + 1][c] == 'T') {
//			return 1;
//		}
//		else {
//			for (int i = 0; i < n; i++) {//生成一个新的迷宫，该迷宫把走过的路设为墙壁，防止走回头路，对应要点6
//				for (int j = 0; j < m; j++) {
//					p_temp[i][j] = p[i][j];
//				}
//			}
//			p_temp[r+1][c] = '#';
//			steps_down = recursion(p, r + 1, c, 4);
//			steps_down++;
//		}
//	}
//	return min(min(min(steps_left, steps_up), steps_right), steps_down);//求4个当中的最小值，不对-1进行比较。如果返回值是-1，表示有3个面是墙壁'#'或者边界
//}

//int recursion(char* p[], int r, int c) {//p表示当前迷宫；r,c表示这次的位置，r为行，c为列，对应要点2
//	int steps_left = -1, steps_up = -1, steps_right = -1, steps_down = -1;//分别表示左上右下各自移动的步数，取最小值返回，至少为1。对应要点3
//	int min(int a, int b);//声明函数
//	
//
//	char** p_temp = new char* [n];//生成一个新的迷宫，该迷宫把走过的路设为墙壁，防止走回头路，对应要点1
//	for (int i = 0; i < n; i++) {
//		p_temp[i] = new char[m];
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			p_temp[i][j] = p[i][j];
//		}
//	}
//	p_temp[r][c] = '#';//新迷宫把当前所处的位置变成墙壁，对应要点1
//
//	if (c > 0 && p[r][c - 1] != '#') {//进行左移，前提是不在边界以及不碰墙壁。对应要求中的1，4和5
//		if (p[r][c - 1] == 'T') {//到达终点
//			return 1;
//		}
//		else {
//			steps_left = recursion(p_temp, r, c - 1);
//			if (steps_left != -1)//如果返回值是-1，说明前面是死路，故不考虑该路线，应当返回-1
//				steps_left++;//当前递归左移了一步，进行记录
//		}
//	}
//	if (r > 0 && p[r - 1][c] != '#') {//上移
//		if (p[r - 1][c] == 'T') {
//			return 1;
//		}
//		else {
//			steps_up = recursion(p_temp, r - 1, c);
//			if (steps_up != -1)
//				steps_up++;
//		}
//	}
//	if (c < m - 1 && p[r][c + 1] != '#') {//右移
//		if (p[r][c + 1] == 'T') {
//			return 1;
//		}
//		else {
//			steps_right = recursion(p_temp, r, c + 1);
//			if (steps_right != -1)
//				steps_right++;
//		}
//	}
//	if (r < n - 1 && p[r + 1][c] != '#') {//下移
//		if (p[r + 1][c] == 'T') {
//			return 1;
//		}
//		else {
//			steps_down = recursion(p_temp, r + 1, c);
//			if (steps_down != -1)
//				steps_down++;
//		}
//	}
//
//	for (int i = 0; i < n; i++) {//新迷宫释放内存
//		delete[]p_temp[i];
//	}
//	delete[]p_temp;
//	return min(min(min(steps_left, steps_up), steps_right), steps_down);//求4个当中的最小值，不对-1进行比较。如果返回值是-1，表示有4个面是墙壁'#'或者边界（包括后来新生成的墙壁）
//}

int recursion(char* p[], int r, int c, int steps = 0) {//p表示当前迷宫；r,c表示这次的位置，r为行，c为列，对应要点2。steps是从入口S到当前位置的步数，每调用一次recursion，就加一步
	int steps_left = -1, steps_up = -1, steps_right = -1, steps_down = -1;//分别表示左上右下移动，是从终点T到当前位置的步数。取最小值返回，至少为1。对应要点3
	int min(int a, int b);//声明函数

	char** p_temp = new char* [n];//生成一个新的迷宫，该迷宫把走过的路设为墙壁，防止走回头路，对应要点1
	for (int i = 0; i < n; i++) {
		p_temp[i] = new char[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			p_temp[i][j] = p[i][j];
		}
	}
	p_temp[r][c] = '#';//新迷宫把当前所处的位置变成墙壁，对应要点1


	if (c > 0 && p[r][c - 1] != '#') {//进行左移，前提是不在边界以及不碰墙壁。对应要求中的1，4和5
		//steps++;//不能这样写，因为后面还要用到steps，不能修改其值。r,c同理
		if (p[r][c - 1] == 'T') {//到达终点
			if (steps + 1 <= shortest_steps) {//更新新的最短路线步数
				shortest_steps = steps + 1;
			}
			return 1;
		}
		else {
			if (steps + 1 == shortest_steps) steps_left=-1;//当前路线还未到达终点就已经等于目前已知最短路线步数，故不考虑该路线，返回-1
			else {
				steps_left = recursion(p_temp, r, c - 1, steps + 1);
				if (steps_left != -1)//如果返回值是-1，说明前面是死路，故不考虑该路线，应当返回-1
					steps_left++;//当前递归左移了一步，进行记录
			}
		}
	}
	if (r > 0 && p[r - 1][c] != '#') {//上移
		if (p[r - 1][c] == 'T') {
			if (steps + 1 <= shortest_steps) {
				shortest_steps = steps + 1;
			}
			return 1;
		}
		else {
			if (steps + 1 == shortest_steps) steps_up= -1;
			else {
				steps_up = recursion(p_temp, r - 1, c, steps + 1);
				if (steps_up != -1)
					steps_up++;
			}
		}
	}
	if (c < m - 1 && p[r][c + 1] != '#') {//右移
		if (p[r][c + 1] == 'T') {
			if (steps + 1 <= shortest_steps) {
				shortest_steps = steps + 1;
			}
			return 1;
		}
		else {
			if (steps + 1 == shortest_steps) steps_right= -1;
			else {
				steps_right = recursion(p_temp, r, c + 1, steps + 1);
				if (steps_right != -1)
					steps_right++;
			}
		}
	}
	if (r < n - 1 && p[r + 1][c] != '#') {//下移
		if (p[r + 1][c] == 'T') {
			if (steps + 1 <= shortest_steps) {
				shortest_steps = steps + 1;
			}
			return 1;
		}
		else {
			if (steps + 1 == shortest_steps) steps_down= -1;
			else {
				steps_down = recursion(p_temp, r + 1, c, steps + 1);
				if (steps_down != -1)
					steps_down++;
			}
		}
	}

	for (int i = 0; i < n; i++) {//新迷宫释放内存
		delete[]p_temp[i];
	}
	delete[]p_temp;
	return min(min(min(steps_left, steps_up), steps_right), steps_down);//求4个当中的最小值，不对-1进行比较。如果返回值是-1，表示有4个面是墙壁'#'或者边界（包括后来新生成的墙壁）
}


int main() {
	cin >> n >> m;
	shortest_steps = n * m-1;//最短路线步数最长的情况（不走回头路），还应该减去'#'的数量，这里没有减
	char** p = new char* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new char[m];
	}

	int S_n, S_m;//入口的行和列
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> p[i][j];
			if (p[i][j] == 'S') { //找到入口
				S_n = i;
				S_m = j;
			}
		}
	}

	int shortest_steps_back;
	shortest_steps_back = recursion(p, S_n, S_m);
	if (shortest_steps_back != -1) {//-1表示入口处已经无路可走
		cout << shortest_steps_back << endl;//反向计算的最短路径
		cout << shortest_steps << endl;//正向计算的最短路径
	}
	else
		cout << "Can't reach the terminal!" << endl;

	for (int i = 0; i < n; i++) {
		delete[]p[i];
	}
	delete[]p;
	return 0;
}