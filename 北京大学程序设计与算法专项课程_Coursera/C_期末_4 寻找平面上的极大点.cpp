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
	for (int i = 0; i < n-1; i++) {//����x�����С�������ð������
		for (int j = 0; j < n - 1 - i; j++) {
			if (p[j].x > p[j + 1].x) {
				coordinates temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}

	int number=0;//������¼�ж��ٸ������
	for (int i = 0; i < n; i++) {
		int flag = 0; //0��ʾδ����������֧�䣬1��ʾ����������֧��
		for (int j = 0; j < n; j++) {
			if (p[i].x == p[j].x && p[i].y == p[j].y) //��������Ƚ�
				continue;
			if (p[i].x <= p[j].x && p[i].y <= p[j].y) //һ�����ֱ�֧�����������Ǹ�������
				flag = 1;
		}
		if (flag == 0) {
			number++;
			if (number == 1) {//��һ�����ݵ����������Ϊǰ�治��','
				printf("(%d,%d)", p[i].x, p[i].y);
			}else
			printf(",(%d,%d)", p[i].x, p[i].y);//δ���ֱ�֧���������������ǰ�����
		}
	}

	delete[]p;
	return 0;
}