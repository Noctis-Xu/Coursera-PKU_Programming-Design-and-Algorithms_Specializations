/*
输入
多组数据。每组第一行是一个不含空格的字符串
第二行是整数n
第三行是n个整数

输出
对每组数据，先依次输出输入字符串的每个字母，并且在每个字母后面加逗号
然后依次再输出输入的n个整数 ，在每个整数后面加逗号
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>
class myclass {
	// 在此处补充你的代码
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