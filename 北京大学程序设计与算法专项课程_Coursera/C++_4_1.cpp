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

    //�ڴ˴�������Ĵ���
    Complex & operator= (const char * str){
        const char* p = strchr(str, '+');//��һ�γ���'+'��ָ��
        //int pos = (p - str) / sizeof(char);//'+'�ǵڼ����ַ�����0����
        r = atof(str);//�ַ���תdouble�����������ֵ��ַ�ʱֹͣ
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