/*
Ҫ�㣺
1.�������߹���·�������������ѭ����������񷴸����ĸ�������·�ߡ�����·�ߡ����������������߹���·����Ϊ�ϰ��ǽ��'#')
2.�������Ҫ����ǰһ�ε�λ�ã����ڵ�һ����˵���Ǵ������S
3.ÿ�εݹ鷵�����·��
4.�жϱ߽�
5.�ж�ǽ��
6.�Ż�����1����ͬһ��ֻ����һ�ε����ڵ����·�����Թ����߷�ֻ�͵�ǰλ���йأ����Ժܶ�������ǿ����ظ����á�����100*100���Թ���һ��10000���㣬�ݹ麯��ֻ��Ҫ������10000���ظ���һ����ļ����ǿ��Ա���ġ�
7.�Ż�����2�������ǰ�ߵ�·�߽�Ҫ������֪�����·�߲�������ֹͣ
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int n, m;//�Թ�n��m��
int** p_steps;//������¼ĳһλ�õ����ڵ���̾��룬��ֹ�ظ����㣬��ӦҪ��6

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

int recursion(char* p[], int r, int c) {//p��ʾ��ǰ�Թ���r,c��ʾ��ε�λ�ã�rΪ�У�cΪ�У���ӦҪ��2
	int steps_left = -1, steps_up = -1, steps_right = -1, steps_down = -1;//�ֱ��ʾ�������¸����ƶ��Ĳ�����ȡ��Сֵ���أ�����Ϊ1����ӦҪ��3
	int min(int a, int b);//��������
	

	char** p_temp = new char* [n];//����һ���µ��Թ������Թ����߹���·��Ϊǽ�ڣ���ֹ�߻�ͷ·����ӦҪ��1
	for (int i = 0; i < n; i++) {
		p_temp[i] = new char[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			p_temp[i][j] = p[i][j];
		}
	}
	p_temp[r][c] = '#';//���Թ��ѵ�ǰ������λ�ñ��ǽ�ڣ���ӦҪ��1

	if (c > 0 && p[r][c - 1] != '#') {//�������ƣ�ǰ���ǲ��ڱ߽��Լ�����ǽ�ڡ���ӦҪ���е�1��4��5
		if (p[r][c - 1] == 'T') {//�����յ�
			steps_left= 1;
		}
		else if (p_steps[r][c - 1] != -1) {//���������-1��˵��֮ǰ�Ѿ�������·�߼�����õ㵽�յ����̾��롣ע�⣬��ʹ֮ǰ�м�������ҵõ�p_steps[r][c-1]=-1��Ҳ���ܹ������ã���Ҫ���¼���һ�飬��Ϊ-1����Ч��
			steps_left = p_steps[r][c - 1];
			//if (steps_left != -1)//���ֵ��-1��˵��֮ǰ�Ѿ����������·���ʲ����Ǹ�·�ߣ�Ӧ������-1����仰�Ǵ�ģ���ʹ֮ǰ�Ѿ��������-1��ҲҪ���¼���õ㣬��Ϊ-1��ʾ��Ч
				steps_left++;//��ǰ�ݹ�������һ�������м�¼
		}
		else {
			steps_left = recursion(p_temp, r, c - 1);
			if (steps_left != -1)//�������ֵ��-1��˵��ǰ������·���ʲ����Ǹ�·�ߣ�Ӧ������-1
				steps_left++;//��ǰ�ݹ�������һ�������м�¼
		}
	}
	if (r > 0 && p[r - 1][c] != '#') {//����
		if (p[r - 1][c] == 'T') {
			steps_up= 1;
		}
		else if (p_steps[r - 1][c] != -1) {
			steps_up = p_steps[r - 1][c];
			steps_up++;
		}
		else {
			steps_up = recursion(p_temp, r - 1, c);
			if (steps_up != -1)
				steps_up++;
		}
	}
	if (c < m - 1 && p[r][c + 1] != '#') {//����
		if (p[r][c + 1] == 'T') {
			steps_right= 1;
		}
		else if (p_steps[r][c + 1] != -1) {
			steps_right = p_steps[r][c + 1];
			steps_right++;
		}
		else {
			steps_right = recursion(p_temp, r, c + 1);
			if (steps_right != -1)
				steps_right++;
		}
	}
	if (r < n - 1 && p[r + 1][c] != '#') {//����
		if (p[r + 1][c] == 'T') {
			steps_down= 1;
		}
		else if (p_steps[r + 1][c] != -1) {
			steps_down = p_steps[r + 1][c];
			steps_down++;
		}
		else {
			steps_down = recursion(p_temp, r + 1, c);
			if (steps_down != -1)
				steps_down++;
		}
	}

	for (int i = 0; i < n; i++) {//���Թ��ͷ��ڴ�
		delete[]p_temp[i];
	}
	delete[]p_temp;
	p_steps[r][c] = min(min(min(steps_left, steps_up), steps_right), steps_down);//��4�����е���Сֵ������-1���бȽϡ��������ֵ��-1����ʾ��4������ǽ��'#'���߽߱磨�������������ɵ�ǽ�ڣ�
	return p_steps[r][c];
}



int main() {
	cin >> n >> m;

	char** p = new char* [n];
	p_steps = new int* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new char[m];
		p_steps[i] = new int[m];
	}

	int S_n, S_m;//��ڵ��к���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> p[i][j];
			p_steps[i][j] = -1; //��ʼ������λ�õ����ڵ����·��Ϊ-1
			if (p[i][j] == 'S') { //�ҵ����
				S_n = i;
				S_m = j;
			}
		}
	}

	int shortest_steps_back;
	shortest_steps_back = recursion(p, S_n, S_m);
	if (shortest_steps_back != -1) {//-1��ʾ��ڴ��Ѿ���·����
		cout << shortest_steps_back << endl;//�����������·��
	}
	else
		cout << "Can't reach the terminal!" << endl;

	for (int i = 0; i < n; i++) {
		delete[]p[i];
		delete[]p_steps[i];
	}
	delete[]p;
	delete[]p_steps;
	return 0;
}