/*����
��дGoodCopy��ģ�壬ʹ�ó���ָ����ʽ���

����
��һ�������� t,��ʾ��������
ÿ�����ݣ�
��һ�������� n , n < 50
�ڶ����� n ������
�������� n ���ַ���

���
�����������ԭ��������Σ���","�ָ�
Ȼ��������ַ���ԭ��������Σ�Ҳ�� ","�ָ�
*/
#include <iostream>
using namespace std;


template <class T>
struct GoodCopy {
	// �ڴ˴�������Ĵ���
	void operator ()(T* start,T* end,T* p) {
		int count = end - start;
		T* temp = new T[count];
		for (int i = 0; i < count; i++) {
			temp[i] = *(start + i);
		}
		for (int i = 0; i < count; i++) {
			*(p + i) = temp[i];
		}
		delete[]temp;
	}
};

int a[200];
int b[200];
string c[200];
string d[200];

template <class T>
void Print(T s, T e) {
	for (; s != e; ++s)
		cout << *s << ",";
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i)
			cin >> a[i];
		GoodCopy<int>()(a, a + m, b);
		Print(b, b + m);
		GoodCopy<int>()(a, a + m, a + m / 2);
		Print(a + m / 2, a + m / 2 + m);

		for (int i = 0; i < m; ++i)
			cin >> c[i];
		GoodCopy<string>()(c, c + m, d);
		Print(c, c + m);
		GoodCopy<string>()(c, c + m, c + m / 2);
		Print(c + m / 2, c + m / 2 + m);
	}
	return 0;
}