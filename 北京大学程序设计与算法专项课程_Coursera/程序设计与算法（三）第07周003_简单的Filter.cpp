/*编写Filter模板，使得程序产生指定输出 不得编写 Filter函数
输入
无

输出
MikeJackLucy
3, 4, 5,
*/

#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template <class T>
T* Filter(T*p1,T*p2,T*p3,bool(*p4)(T ns)) {
	int count = p2 - p1;
	int j = 0;
	for (int i = 0; i < count; ++i) {
		if ((*p4)(*(p1 + i))) {
			*(p3 + j) = *(p1 + i);
			++j;
		}
	}
	return p3 + j;
}

bool LargerThan2(int n)
{
	return n > 2;
}
bool LongerThan3(string s)
{
	return s.length() > 3;
}

string as1[5] = { "Tom","Mike","Jack","Ted","Lucy" };
string as2[5];
int  a1[5] = { 1,2,3,4,5 };
int a2[5];
int main() {
	string* p = Filter(as1, as1 + 5, as2, LongerThan3);
	for (int i = 0; i < p - as2; ++i)//p-as2表示as2里的元素个数，所以p应该指向as2最后一个元素
		cout << as2[i];
	cout << endl;
	int* p2 = Filter(a1, a1 + 5, a2, LargerThan2);
	for (int i = 0; i < p2 - a2; ++i)
		cout << a2[i] << ",";
	return 0;
}