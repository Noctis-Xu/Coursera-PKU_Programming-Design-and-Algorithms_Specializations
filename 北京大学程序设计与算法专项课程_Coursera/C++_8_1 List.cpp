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

//�����õ���vector����Mylist��ʵ��

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