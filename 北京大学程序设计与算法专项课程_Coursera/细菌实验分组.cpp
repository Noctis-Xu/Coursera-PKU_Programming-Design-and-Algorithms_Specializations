#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//#define DIFFERENCE 2
using namespace std;

struct CultureDish {
	int number;
	int beginning;
	int end;
	float rate;
	bool IsAsubtype;//是否是A亚型
};


int main() {
	int n;
	/*input*/
	cin >> n;
	CultureDish* p = new CultureDish[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i].number;
		cin >> p[i].beginning;
		cin >> p[i].end;
		p[i].rate = (float)p[i].end / (float)p[i].beginning;
	}

	/*process*/
	for (int i = 0; i < n - 1; i++) {//选择排序,按rate从小到大排序
		int min = i;
		for (int j = i; j < n - 1; j++) {
			if (p[min].rate > p[j + 1].rate) {
				min = j + 1;
			}
		}
		if (min != i) { //如果最小值的索引不是假设的索引，则交换位置
			CultureDish temp = p[i];
			p[i] = p[min];
			p[min] = temp;
		}
	}
	//自己的分组方法：凑一个差值。不如下面的标准答案。
	//p[0].IsAsubtype = false; //排名第一的、rate最小的培养皿必定是B亚型
	//for (int i = 0; i < n - 1; i++) {
	//	p[i + 1].IsAsubtype = p[i + 1].rate / p[i].rate > DIFFERENCE || p[i].IsAsubtype;
	//} //从中间某个值开始一直为A亚型；

	int x1 = 0;
	for (int i = 0; i < n - 1; i++) {
		if (((p[n-1].rate - p[i + 1].rate) < (p[i + 1].rate - p[i].rate)) && ((p[i].rate - p[0].rate) < (p[i + 1].rate - p[i].rate))){
			x1 = i;
			break;
		}
	}
	for (int i = 0; i <= x1; i++) {
		p[i].IsAsubtype = false;
	}
	for (int i = x1+1; i < n; i++) {
		p[i].IsAsubtype = true;
	}/*这题本质就是把一堆数，按大小分成两堆，大的去大堆，小的去小堆。最大的数肯定是大堆的，最小的数肯定是小堆的。
	我们的目标是要找到一个区分点x，使得 >= x的数都是大堆，<x的都是小堆。比如5000, 4999, 5060, 230, 240，4999就是x。
	把数字排好序，看起来就是这样的：
	max >= ... >= x > x' >= ... >= min（x'是比x小的相邻的数，也就是小堆的最大数）
	大组的组内差异就是max - x，小组的组内差异就是x'-min，组间差异就是x-x'。我们就是要找到这样的x，使得
	max - x < x - x' && x' - min < x - x'。排好序遍历一遍数组就能找到了。*/
	/*根据题意”亚种间任何两组细菌的繁殖率之差都比亚种内部两组细菌的繁殖率之差大”，对应的表达是：
	大组组内最大差值<组间最小差值 && 小组组间最大差值<组间最小差值
	写成表达式就是：max-x<x-x' && x'-min<x-x'*/

	int A_count = 0, B_count = 0;//统计A、B亚型的数量
	for (int i = 0; i < n; i++) {
		p[i].IsAsubtype == true ? A_count++ : B_count++;
	}

	/*output*/
	cout << A_count << endl;
	for (int i = 0; i < n; i++) {
		if (p[i].IsAsubtype == true)
			cout << p[i].number << endl;
	}
	cout << B_count << endl;
	for (int i = 0; i < n; i++) {
		if (p[i].IsAsubtype == false)
			cout << p[i].number << endl;
	}

	delete[] p;
	return 0;
}