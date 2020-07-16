/*编写MyForeach模板，使程序按要求输出 不得编写 MyForeach函数
输入
多组数据
每组数据第一行是两个整数 m 和 n ,都不超过 50
第二行是m个不带空格的字符串
第三行是 n个整数

输出
对每组数据
第一行输出所有输入字符串连在一起的结果
第二行输出输入中的每个整数加1的结果
*/

#include <iostream>
#include <string>
using namespace std;

// 在此处补充你的代码
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
