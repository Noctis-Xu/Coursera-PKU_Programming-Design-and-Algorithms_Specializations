/*
����
дһ����������������
new id �����½�һ��ָ�����Ϊid������(id<10000)
add id num��������Ϊid�����м�������num
merge id1 id2�����ϲ�����id1��id2�е���������id2���
unique id����ȥ������id���ظ���Ԫ��
out id ������С����������Ϊid�������е�Ԫ�أ��Կո����

����
��һ��һ����n����ʾ�ж��ٸ�����( n����������������)���Ժ�n��ÿ��һ�����
���
����ĿҪ�������

��������
16
new 1
new 2
add 1 1
add 1 2
add 1 3
add 2 1
add 2 2
add 2 3
add 2 4
out 1
out 2
merge 1 2
out 1
out 2
unique 1
out 1

�������
1 2 3
1 2 3 4
1 1 2 2 3 3 4

1 2 3 4
*/

//�����õ���unordered_map��ʵ�ֵģ�����hasp_map
//https://blog.csdn.net/wuchenfengXXX/article/details/72802424

#include <iostream>
#include <iterator>
#include <list>//˫������
#include <vector>
#include <string>
//#include <hash_map>
#include <unordered_map>
#include <algorithm>
using namespace std;

template <class T>
struct print
{
	void operator()(const T& x)
	{
		cout << x << " ";
	}
};

int main()
{
	int n;
	cin >> n;
	unordered_map<int, list<int> > myDb;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (str == "new")
		{
			int id;
			cin >> id;
			myDb[id] = list<int>();
		}
		else if (str == "add")
		{
			int id, num;
			cin >> id >> num;
			myDb[id].push_back(num);
		}
		else if (str == "merge")
		{
			int id1, id2;
			cin >> id1 >> id2;
			myDb[id1].sort();
			myDb[id2].sort();
			myDb[id1].merge(myDb[id2]);
			myDb.erase(id2);
		}
		else if (str == "unique")
		{
			int id;
			cin >> id;
			myDb[id].sort();
			myDb[id].unique();
		}
		else if (str == "out")
		{
			int id;
			cin >> id;
			for_each(myDb[id].begin(), myDb[id].end(), print<int>());
			cout << endl;
		}

	}
	return 0;
}