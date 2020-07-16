/*��дMyForeachģ�壬ʹ����Ҫ����� ���ñ�д MyForeach����
����
��������
ÿ�����ݵ�һ������������ m �� n ,�������� 50
�ڶ�����m�������ո���ַ���
�������� n������

���
��ÿ������
��һ��������������ַ�������һ��Ľ��
�ڶ�����������е�ÿ��������1�Ľ��
*/

#include <iostream>
#include <string>
using namespace std;

// �ڴ˴�������Ĵ���
template <class T1 >
void MyForeach(T1* p1, T1* p2, void(*p)(T1 s)) {
	int count = p2 - p1;
	T1 sum=*p1;
	for (int i =1; i < count; ++i) {
		sum = sum + *(p1 + i);
	}
	(*p)(sum);
}
template <class T1 >
void MyForeach(T1* p1, T1* p2, void(*p)(T1& n)) {
	int count = p2 - p1;
	for (int i = 0; i < count; ++i) {
		(*p)(*(p1 + i));
	}
}

void Print(string s)
{
	cout << s;
}
void Inc(int& n)
{
	++n;
}
string Array[100];
int a[100];
int main() {
	int m, n;
	while (cin >> m >> n) {
		for (int i = 0; i < m; ++i)
			cin >> Array[i];
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		MyForeach(Array, Array + m, Print);
		cout << endl;
		MyForeach(a, a + n, Inc);
		for (int i = 0; i < n; ++i)
			cout << a[i] << ",";
		cout << endl;
	}
	return 0;
}
