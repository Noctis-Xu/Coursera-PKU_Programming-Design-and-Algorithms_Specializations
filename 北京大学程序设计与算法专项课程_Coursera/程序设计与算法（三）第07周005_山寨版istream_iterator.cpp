/*���� ģ��C++��׼ģ���istream_iterator�÷���ʵ��CMyistream_iteratorʹ�ó���Ҫ�����
����
��һ��������t����ʾ��t������
ÿ������һ�У����������������ַ������ַ����ǲ����ո��

���
��ÿ�����ݣ��������
�ڵ�һ�������һ����
�ڶ���ԭ��������������

��ʾ
C++��׼ģ��� istream_iteratorģ��ʹ��˵����

�乹�캯��ִ�й����оͻ�Ҫ�����룬Ȼ��ÿ��ִ��++�����ȡ�������е���һ����Ŀ��ִ�� * �򷵻��ϴδ��������ж�ȡ����Ŀ�����磬�����������ʱ���ͻ�ȴ��û��������ݣ��������ݺ����Ż������
#include
#include
using namespace std;
int main() {
istream_iterator inputInt(cin);
return 0;
}

�����������ʱ��������� 12 34 �����������ǣ� 12,12
#include
#include
using namespace std;
int main()
{
istream_iterator inputInt(cin);
cout << * inputInt << "," << * inputInt << endl;
return 0;
}

�����������ʱ��������� 12 34 56�����������ǣ� 12,56
#include
#include
using namespace std;
int main()
{
istream_iterator inputInt(cin);
cout << * inputInt << "," ;
inputInt ++;
inputInt ++;
cout << * inputInt;
return 0;
}
*/


#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
	// �ڴ˴�������Ĵ���
	T n[3];
	T* p = n;
public:
	CMyistream_iterator(istream& a) {
		cin.ignore();
		for (int i = 0; i<3&&cin.peek()!='\n';++i) {
			cin >> n[i];
		}
		
	}
	CMyistream_iterator& operator++(int) {
		p++;
		return *this;
	}
	T operator*() {
		return *p;
	}
};


int main()
{
	int t;
	cin >> t;
	while (t--) {
		CMyistream_iterator<int> inputInt(cin);
		int n1, n2, n3;
		n1 = *inputInt; //���� n1
		int tmp = *inputInt;
		cout << tmp << endl;
		inputInt++;
		n2 = *inputInt; //���� n2
		inputInt++;
		n3 = *inputInt; //���� n3
		cout << n1 << " " << n2 << " " << n3 << " ";
		CMyistream_iterator<string> inputStr(cin);
		string s1, s2;
		s1 = *inputStr;
		inputStr++;
		s2 = *inputStr;
		cout << s1 << " " << s2 << endl;
	}
	return 0;
}