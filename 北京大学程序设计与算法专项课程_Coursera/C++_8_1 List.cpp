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

//这里用的是vector里存放Mylist来实现

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Mylist {
public:
	int ID;
	list<int> L;
};

template<class T>
T Myfind(T begin, T end, int id) {
	for (; begin != end; ++begin) {
		if (begin->ID == id) {
			return begin;
		}
	}
}

template <class T>
void Printlist(const list<T> ls){
	int size = ls.size();
	if (size > 0) {
		typename list<T>::const_iterator p;
		for (p = ls.begin(); p != ls.end(); ++p) {
			cout << *p << " ";
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<Mylist> v;
	for (int i = 0; i < n; ++i) {
		string command;
		cin >> command;
		if (command == "new") {
			Mylist t;
			cin >> t.ID;
			v.push_back(t);
		}
		if (command == "add") {
			int id, num;
			cin >> id >> num;
			vector<Mylist>::iterator p = Myfind(v.begin(), v.end(), id);
			p->L.push_back(num);
		}
		else if (command == "merge") {
			int id1, id2;
			cin >> id1 >> id2;
			vector<Mylist>::iterator p1 = Myfind(v.begin(), v.end(), id1);
			vector<Mylist>::iterator p2 = Myfind(v.begin(), v.end(), id2);
			p1->L.merge(p2->L);
		}
		else if (command == "unique") {
			int id;
			cin >> id;
			vector<Mylist>::iterator p = Myfind(v.begin(), v.end(), id);
			p->L.unique();
		}
		else if (command == "out") {
			int id;
			cin >> id;
			vector<Mylist>::iterator p = Myfind(v.begin(), v.end(), id);
			p->L.sort();
			Printlist(p->L);
			cout << endl;
		}
	}

	return 0;
}