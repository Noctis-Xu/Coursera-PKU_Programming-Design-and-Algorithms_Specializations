/*读入两个整数，输出两个整数 ，直到碰到-1
输入
多组数据，每组一行，是两个整数

输出
对每组数据，原样输出
当碰到输入中出现-1 时，程序结束
输入中保证会有 -1
*/


#include <iostream>
using namespace std;
class MyCin
{
    // 在此处补充你的代码
    bool bool_mycin=true;
public:
    MyCin& operator >>(int& n) {

        cin >> n;
        if (n == -1) {
            bool_mycin = false;
        }
        return *this;
    }
    operator bool() { //自动把MyCin的对象进行bool强制类型转换！
        return bool_mycin;
    }
};
int main()
{
    MyCin m;
    int n1, n2;
    while (m >> n1 >> n2)
        cout << n1 << " " << n2 << endl;
    return 0;
}