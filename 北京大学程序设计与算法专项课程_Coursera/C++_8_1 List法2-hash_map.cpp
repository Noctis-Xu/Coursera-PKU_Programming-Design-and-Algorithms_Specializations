/*
描述
写一个程序完成以下命令：
new id ——新建一个指定编号为id的序列(id<10000)
add id num——向编号为id的序列加入整数num
merge id1 id2——合并序列id1和id2中的数，并将id2清空
unique id——去掉序列id中重复的元素
out id ——从小到大输出编号为id的序列中的元素，以空格隔开

输入
第一行一个数n，表示有多少个命令( n＜＝２０００００)。以后n行每行一个命令。
输出
按题目要求输出。

样例输入
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

样例输出
1 2 3
1 2 3 4
1 1 2 2 3 3 4

1 2 3 4
*/

//这里用的是unordered_map来实现的，就是hasp_map
//https://blog.csdn.net/wuchenfengXXX/article/details/72802424

#include <iostream>
#include <iterator>
#include <list>//双向链表
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