/*��дFilterģ�壬ʹ�ó������ָ����� ���ñ�д Filter����
����
��

���
MikeJackLucy
3, 4, 5,
*/

#include <iostream>
#include <string>
using namespace std;
// �ڴ˴�������Ĵ���
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
	for (int i = 0; i < p - as2; ++i)//p-as2��ʾas2���Ԫ�ظ���������pӦ��ָ��as2���һ��Ԫ��
		cout << as2[i];
	cout << endl;
	int* p2 = Filter(a1, a1 + 5, a2, LargerThan2);
	for (int i = 0; i < p2 - a2; ++i)
		cout << a2[i] << ",";
	return 0;
}