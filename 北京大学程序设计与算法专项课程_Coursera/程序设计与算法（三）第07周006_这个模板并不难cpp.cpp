/*
����
�������ݡ�ÿ���һ����һ�������ո���ַ���
�ڶ���������n
��������n������

���
��ÿ�����ݣ���������������ַ�����ÿ����ĸ��������ÿ����ĸ����Ӷ���
Ȼ����������������n������ ����ÿ����������Ӷ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>
class myclass {
	// �ڴ˴�������Ĵ���
	T *p=new T[100];
	int size;
public:
	myclass(const T* pa,int n):size(n){
		for (int i = 0; i < size; i++) {
			*(p + i) = *(pa + i);
		}
		
	}

	~myclass() {
		delete[] p;
	}
	void Show()
	{
		for (int i = 0; i < size; i++) {
			cout << p[i] << ",";
		}
		cout << endl;
	}
};

int a[100];
int main() {
	//freopen("C:/Users/xuboy/Desktop/test.txt", "r", stdin);
	char line[100];
	while (cin >> line) {
		myclass<char> obj(line, strlen(line));;
		obj.Show();
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		myclass<int> obj2(a, n);
		obj2.Show();
	}
	return 0;
}