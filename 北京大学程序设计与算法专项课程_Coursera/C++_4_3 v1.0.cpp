/*
写一个二维数组类 Array2,使得下面程序的输出结果是：
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
*/

#include <iostream>
#include <cstring>
using namespace std;

// 在此处补充你的代码
class Array2 {//初始化只分配内存；要有复制构造函数
	int** p = NULL;//数组元素指针
	bool IsCol = false;//如果IsCol为false，表示当前指向行，为true则指向列
	int r = 0, c = 0;//用来记录当前指向第几行第几列
	int size_r = 0, size_c = 0;//数组的行数和列数
	friend ostream& operator <<(ostream& os, const Array2& a);
public:
	Array2(int i = 0, int j = 0) :size_r(i), size_c(j) {//构造函数
		if (i > 0 && j > 0) {
			p = new int* [i];
			for (int t = 0; t < i; t++) {
				p[t] = new int[j];
			}
		}
		//cout << this << endl;
	}
	//Array2(const Array2& a) {//复制构造函数,深拷贝，防止重复delete同一片内存空间
	//	size_r = a.size_r;
	//	size_c = a.size_c;
	//	if (size_r > 0 && size_c > 0) {	
	//		p = new int* [size_r];
	//		for (int t = 0; t < size_r; t++) {
	//			p[t] = new int[size_c];
	//			memcpy(p[t], a.p[t], sizeof(int) * size_c);
	//		}
	//	}
	//}
	Array2& operator[](int n) {
		if (!IsCol)r = n, IsCol = true;
		else c = n, IsCol = false;
		return *this;
	}
	int& operator=(int n) {
		p[r][c] = n;
		return p[r][c];
	}
	int operator()(int i, int j) {
		return p[i][j];
	}
	Array2& operator=(const Array2& a) {//深拷贝
		size_r = a.size_r;
		size_c = a.size_c;
		if (size_r > 0 && size_c > 0) {
			p = new int* [size_r];
			for (int t = 0; t < size_r; t++) {
				p[t] = new int[size_c];
				memcpy(p[t], a.p[t], sizeof(int) * size_c);
			}
		}
		return *this;
	}
	~Array2() {
		//cout << this << endl;
		for (int t = 0; t < size_r; t++) {
			delete[]p[t];
			//cout << "delete" << t << endl;
		}
		delete[]p;
		//cout << "delete all" << endl;
	}

};
ostream& operator <<(ostream& os, const Array2& a) {
	cout << a.p[a.r][a.c];
	return os;
}

int main() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;
	b = a;//注意，这里是赋值语句，非初始化语句！！！不会调用复制构造函数
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}