/*���õݹ飬������⣬��BFS˼·���ٶȼ���*/

/*˼·
�ڿ�ʼѭ��ǰ�Ȱ�S��Ϊ#
��S��ʼ��ֱ���ҵ�T����ѭ��(��flag����Ƿ��ҵ�T���ҵ�T��flagΪtrue������Ϊ��)
1.��һ��ѭ����
�������ж���������4�������ĸ�������һ�������ߣ������Ǳ߽������'.'����T��
��Ȼ���ж����п����ߵ���һ���ǲ���T���ǵĻ�flag=true������ѭ�������ǵĻ�����һ�������ߵĵ㶼��Ϊ#����������p_ready��¼��һ�������ߵĵ�
��steps++
2.�ڶ���ѭ�����������е�ÿ��Ԫ���ٽ��е�1��������Ȼ����һ���µ������¼��һ�������ߵĵ㣬ע���¼ǰ��֮ǰ������Ԫ�����
3.������ѭ�������µ������е�ÿ��Ԫ���ٽ���������1��������Ȼ����һ���µ������¼��һ�������ߵĵ�
���԰�S�ȷ���p_ready���У�������1�����2���͵��������Է���ͬһ��ѭ����
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include "time.h"//��������ʱ��

#define p_ready_amount 200

using namespace std;
int n, m;

struct {
	int r = -1;//��
	int c = -1;//��
}p_ready[p_ready_amount],p_ready_temp[p_ready_amount];//p_ready_temp������ʱ��¼�²�������һ�����ߵĵ�

int main() {
	cin >> n >> m;
	char** p = new char* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new char[m];
	}
	int S_n, S_m;//��ڵ��к���
	for (int i = 0; i < n; i++) {//���Թ���ֵ
		for (int j = 0; j < m; j++) {
			cin >> p[i][j];
			if (p[i][j] == 'S') { //�ҵ����
				S_n = i;
				S_m = j;
			}
		}
	}

	//clock_t start_time, end_time;
	//start_time = clock();   //��ȡ��ʼִ��ʱ��

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
		for (int i = 0; p_ready[i].r != -1; i++) {//��p_ready�����е�ÿ��Ԫ�ؽ��б�����-1��ʾ��β
			if (p_ready[i].c > 0 && p[p_ready[i].r][p_ready[i].c - 1] != '#') {//�ж���һ���Ƿ��������
				if (p[p_ready[i].r][p_ready[i].c - 1] == 'T') {//�����յ�
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
			if (p_ready[i].r > 0 && p[p_ready[i].r - 1][p_ready[i].c] != '#') {//����
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
			if (p_ready[i].c < m - 1 && p[p_ready[i].r][p_ready[i].c + 1] != '#') {//����
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
			if (p_ready[i].r < n - 1 && p[p_ready[i].r + 1][p_ready[i].c] != '#') {//����
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
		p_ready_temp[j].r = -1;//��β
	}

	cout << steps << endl;


	for (int i = 0; i < n; i++) {
		delete[]p[i];
	}
	delete[]p;

	//end_time = clock();     //��ȡ����ʱ��
	//double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	//printf("%f seconds\n", Times);

	return 0;
}