#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	int m, k;
	cin >> m >> k;

	int bits = 0;
	int m_temp = m;
	while (m_temp != 0) {//获得m一共有几个位数，保存在bits中
		m_temp = m_temp / 10;
		bits++;
	}
	//cout << bits<<endl;

	int* p = new int[bits];
	int bits_temp = bits;
	m_temp = m;
	int numberOf3 = 0;
	for (int i = 0; i < bits; i++) {
		p[i] = m_temp / pow(10, bits_temp - 1);// 当输入数据是438,则pow(10, bits_temp - 1)=100，p[i]=438/100=4
		m_temp = m_temp - p[i] * pow(10, bits_temp - 1); //m_temp=438-400=38
		bits_temp--;//bits_temp=2,因为38只有2位
		if (p[i] == 3) numberOf3++;//计算有几个3
	}
	//cout << numberOf3<<endl;

	if (m % 19 == 0 && numberOf3 == k) {
		cout << "YES";
	}
	else cout << "NO";

	delete[]p;
	return 0;
}