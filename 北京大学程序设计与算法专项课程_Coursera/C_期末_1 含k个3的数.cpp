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
	while (m_temp != 0) {//���mһ���м���λ����������bits��
		m_temp = m_temp / 10;
		bits++;
	}
	//cout << bits<<endl;

	int* p = new int[bits];
	int bits_temp = bits;
	m_temp = m;
	int numberOf3 = 0;
	for (int i = 0; i < bits; i++) {
		p[i] = m_temp / pow(10, bits_temp - 1);// ������������438,��pow(10, bits_temp - 1)=100��p[i]=438/100=4
		m_temp = m_temp - p[i] * pow(10, bits_temp - 1); //m_temp=438-400=38
		bits_temp--;//bits_temp=2,��Ϊ38ֻ��2λ
		if (p[i] == 3) numberOf3++;//�����м���3
	}
	//cout << numberOf3<<endl;

	if (m % 19 == 0 && numberOf3 == k) {
		cout << "YES";
	}
	else cout << "NO";

	delete[]p;
	return 0;
}