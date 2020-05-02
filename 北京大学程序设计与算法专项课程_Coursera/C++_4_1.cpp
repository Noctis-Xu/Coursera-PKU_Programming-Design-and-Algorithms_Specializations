#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r, i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }

    //在此处补充你的代码
    Complex & operator= (const char * str){
        const char* p = strchr(str, '+');//第一次出现'+'的指针
        //int pos = (p - str) / sizeof(char);//'+'是第几个字符，从0计数
        r = atof(str);//字符串转double，遇到非数字的字符时停止
        i = atof(++p);
        return *this;
    }
   
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}