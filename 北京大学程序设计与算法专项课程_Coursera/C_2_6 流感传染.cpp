#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n;

	//������ά��̬����
	char** p; //����ָ�룬ָ��char��ָ���ָ��
	p = new char* [n]; //char��ָ������[n]
	for (int i = 0; i < n; i++) {
		p[i] = new char[n]; //char��ָ�������е�һ��ָ��ָ��char������[n]
	}
	//����ֵ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
	cin >> m;

	//process
	char** p_y = new char* [n]; //p_y����ǰһ�������
	for (int i = 0; i < n; i++) {
		p_y[i] = new char[n];
	}

	for (int d = 2; d <= m; d++) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				p_y[u][v] = p[u][v]; //��ǰһ������ݽ��б��ݣ���ֹ�ڸ��½��������ʱ��ʧǰһ�������
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (p[i][j] == '.' && (j >= 1 && p_y[i][j - 1] == '@' || j < n - 1 && p_y[i][j + 1] == '@' || i >= 1 && p_y[i - 1][j] == '@' || i < n - 1 && p_y[i + 1][j] == '@'))
					p[i][j] = '@';
			}
		}
	}

	int count=0; //ͳ���ܻ�������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i][j] == '@')
				count++;
		}
	}

	//���
	/*for (int i = 0; i < n; i++) {//���ÿһ�о�������
		for (int j = 0; j < n; j++) {
			cout << p[i][j];
		}
		cout << endl;
	}*/ 
	cout << count; //���������

	for (int i = 0; i < n; i++) {
		delete[] p[i];
		delete[] p_y[i];
	}
	delete[] p;
	delete[] p_y;
	return 0;
}