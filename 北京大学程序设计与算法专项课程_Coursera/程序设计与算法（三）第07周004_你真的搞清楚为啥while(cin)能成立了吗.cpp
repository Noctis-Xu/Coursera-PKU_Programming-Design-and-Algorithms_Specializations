/*������������������������� ��ֱ������-1
����
�������ݣ�ÿ��һ�У�����������

���
��ÿ�����ݣ�ԭ�����
�����������г���-1 ʱ���������
�����б�֤���� -1
*/


#include <iostream>
using namespace std;
class MyCin
{
    // �ڴ˴�������Ĵ���
    bool bool_mycin=true;
public:
    MyCin& operator >>(int& n) {

        cin >> n;
        if (n == -1) {
            bool_mycin = false;
        }
        return *this;
    }
    operator bool() { //�Զ���MyCin�Ķ������boolǿ������ת����
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