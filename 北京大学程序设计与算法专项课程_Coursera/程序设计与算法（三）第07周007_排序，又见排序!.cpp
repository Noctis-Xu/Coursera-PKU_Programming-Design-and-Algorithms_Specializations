/*����:�Լ���дһ���ܶ��κ����͵�������������mysort����ģ�档ֻ��дһ��mysortģ�壬����дmysort������
����
��

���
4,8,10,11,123,
123,11,10,8,4,
1.4,1.2,1.8,3.1,3.2,2.1,
*/


#include <iostream>
using namespace std;

bool Greater2(int n1, int n2)
{
    return n1 > n2;
}
bool Greater1(int n1, int n2)
{
    return n1 < n2;
}
bool Greater3(double d1, double d2)
{
    return d1 < d2;
}

template <class T1, class T2>
void mysort(T1 *p1,T1 *p2,T2(*p)(T1 n1,T1 n2)){
    int count = p2 - p1;
    T1 temp;
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - 1 - i; ++j) {
            if ((*p)(*(p1 + j + 1), *(p1 + j))){
                temp = *(p1 + j + 1);
                *(p1 + j + 1) = *(p1 + j);
                *(p1 + j)=temp;
            }
        }
    }
}

#define NUM 5
int main()
{
    int an[NUM] = { 8,123,11,10,4 };
    mysort(an, an + NUM, Greater1); //��С�������� 
    for (int i = 0; i < NUM; i++)
        cout << an[i] << ",";
    mysort(an, an + NUM, Greater2); //�Ӵ�С���� 
    cout << endl;
    for (int i = 0; i < NUM; i++)
        cout << an[i] << ",";
    cout << endl;
    double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1 };
    mysort(d + 1, d + 5, Greater3); //��������±�1���±�4��С�������� 
    for (int i = 0; i < 6; i++)
        cout << d[i] << ",";
    return 0;
}