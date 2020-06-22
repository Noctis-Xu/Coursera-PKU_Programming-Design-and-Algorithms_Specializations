/*
输入
无

输出
TomJackMaryJohn
10
*/

#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T* p1, T* p2)
	// 在此处补充你的代码
{
	int count = p2 - p1;
	T sum=*p1;
	for (int i = 1; i < count; i++) {
		sum = sum + *(p1 + i);
	}
	return sum;
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John" };
	cout << SumArray(array, array + 4) << endl;
	int a[4] = { 1, 2, 3, 4 };  //提示：1+2+3+4 = 10
	cout << SumArray(a, a + 4) << endl;
	return 0;
}
