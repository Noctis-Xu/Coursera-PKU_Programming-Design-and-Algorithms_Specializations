#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//#define DIFFERENCE 2
using namespace std;

struct CultureDish {
	int number;
	int beginning;
	int end;
	float rate;
	bool IsAsubtype;//�Ƿ���A����
};


int main() {
	int n;
	/*input*/
	cin >> n;
	CultureDish* p = new CultureDish[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i].number;
		cin >> p[i].beginning;
		cin >> p[i].end;
		p[i].rate = (float)p[i].end / (float)p[i].beginning;
	}

	/*process*/
	for (int i = 0; i < n - 1; i++) {//ѡ������,��rate��С��������
		int min = i;
		for (int j = i; j < n - 1; j++) {
			if (p[min].rate > p[j + 1].rate) {
				min = j + 1;
			}
		}
		if (min != i) { //�����Сֵ���������Ǽ�����������򽻻�λ��
			CultureDish temp = p[i];
			p[i] = p[min];
			p[min] = temp;
		}
	}
	//�Լ��ķ��鷽������һ����ֵ����������ı�׼�𰸡�
	//p[0].IsAsubtype = false; //������һ�ġ�rate��С��������ض���B����
	//for (int i = 0; i < n - 1; i++) {
	//	p[i + 1].IsAsubtype = p[i + 1].rate / p[i].rate > DIFFERENCE || p[i].IsAsubtype;
	//} //���м�ĳ��ֵ��ʼһֱΪA���ͣ�

	int x1 = 0;
	for (int i = 0; i < n - 1; i++) {
		if (((p[n-1].rate - p[i + 1].rate) < (p[i + 1].rate - p[i].rate)) && ((p[i].rate - p[0].rate) < (p[i + 1].rate - p[i].rate))){
			x1 = i;
			break;
		}
	}
	for (int i = 0; i <= x1; i++) {
		p[i].IsAsubtype = false;
	}
	for (int i = x1+1; i < n; i++) {
		p[i].IsAsubtype = true;
	}/*���Ȿ�ʾ��ǰ�һ����������С�ֳ����ѣ����ȥ��ѣ�С��ȥС�ѡ��������϶��Ǵ�ѵģ���С�����϶���С�ѵġ�
	���ǵ�Ŀ����Ҫ�ҵ�һ�����ֵ�x��ʹ�� >= x�������Ǵ�ѣ�<x�Ķ���С�ѡ�����5000, 4999, 5060, 230, 240��4999����x��
	�������ź��򣬿��������������ģ�
	max >= ... >= x > x' >= ... >= min��x'�Ǳ�xС�����ڵ�����Ҳ����С�ѵ��������
	��������ڲ������max - x��С������ڲ������x'-min�����������x-x'�����Ǿ���Ҫ�ҵ�������x��ʹ��
	max - x < x - x' && x' - min < x - x'���ź������һ����������ҵ��ˡ�*/
	/*�������⡱���ּ��κ�����ϸ���ķ�ֳ��֮��������ڲ�����ϸ���ķ�ֳ��֮��󡱣���Ӧ�ı���ǣ�
	������������ֵ<�����С��ֵ && С���������ֵ<�����С��ֵ
	д�ɱ��ʽ���ǣ�max-x<x-x' && x'-min<x-x'*/

	int A_count = 0, B_count = 0;//ͳ��A��B���͵�����
	for (int i = 0; i < n; i++) {
		p[i].IsAsubtype == true ? A_count++ : B_count++;
	}

	/*output*/
	cout << A_count << endl;
	for (int i = 0; i < n; i++) {
		if (p[i].IsAsubtype == true)
			cout << p[i].number << endl;
	}
	cout << B_count << endl;
	for (int i = 0; i < n; i++) {
		if (p[i].IsAsubtype == false)
			cout << p[i].number << endl;
	}

	delete[] p;
	return 0;
}