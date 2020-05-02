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
	const int* p_start;//数组开头地址
	int* p_r;//行指针
	int* p_c;//列指针
	int* p;//数组元素指针
public:
	Array2(int i = 0, int j = 0) {//构造函数
		if (i == 0)p = NULL;
		else p = new int[i, j];
		p_start = p;
	}
	//Array2(const Array2& a) {//复制构造函数
	//	p = a.p;
	//}
	int& operator[](int n) {
		p_r = (int*)p_start;
		p_r = ;
		return p[n];
	}
	Array2& operator=(int n) {

		return *this;
	}
	int operator()(int m, int n) {
		return p[m, n];
	}
	~Array2(){
		delete[]p;
	}
};
//ostream& operator <<(ostream& os, const Array2 &a) {
//	cout << ;
//	return os;
//}

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
	Array2 b; b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}