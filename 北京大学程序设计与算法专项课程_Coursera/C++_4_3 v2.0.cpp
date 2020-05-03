/*
дһ����ά������ Array2,ʹ�����������������ǣ�
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
*/
//��c++_4_3 v1.0��֮ͬ�����ڣ�������˶�[]�����أ�ֻ��Ҫ����һ��

#include <iostream>
#include <cstring>
using namespace std;

// �ڴ˴�������Ĵ���
class Array2 {//��ʼ��ֻ�����ڴ棻Ҫ�и��ƹ��캯��
	int** p = NULL;//����Ԫ��ָ��
	//bool IsCol = false;//���IsColΪfalse����ʾ��ǰָ���У�Ϊtrue��ָ����
	//int r = 0, c = 0;//������¼��ǰָ��ڼ��еڼ���
	int size_r = 0, size_c = 0;//���������������
	friend ostream& operator <<(ostream& os, const Array2& a);
public:
	Array2(int i = 0, int j = 0) :size_r(i), size_c(j) {//���캯��
		if (i > 0 && j > 0) {
			p = new int* [i];
			for (int t = 0; t < i; t++) {
				p[t] = new int[j];
			}
		}
		//cout << this << endl;
	}
	int*& operator[](int n) {//����ֻ��Ҫ���ص�1��[]����Ϊ���ص�p[n]������int*���͵ģ�ָ�뱾������[]���ܵģ����Բ���Ҫ�ٴ����ء�
		return p[n];
	}
	/*int& operator=(int n) {
		p[r][c] = n;
		return p[r][c];
	}*/
	int operator()(int i, int j) {
		return p[i][j];
	}
	Array2& operator=(const Array2& a) {//���
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
//ostream& operator <<(ostream& os, const Array2& a) {
//	cout << a.p[a.r][a.c];
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
	Array2 b;
	b = a;//ע�⣬�����Ǹ�ֵ��䣬�ǳ�ʼ����䣡����������ø��ƹ��캯��
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}