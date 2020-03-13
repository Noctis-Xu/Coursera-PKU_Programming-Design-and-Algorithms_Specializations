#include <iostream>
using namespace std;

int Looking_Subscript()
{
	int x[100] = { 0 }, total = 0;
	cin >> total;
	for (int i = 0; i < total; i++)
	{
		cin >> x[i];
		if (x[i] == i)
		{
			cout << i << endl;
			return 1;
		}
	}
	cout << 'N' << endl;
	return 0;
}

int main()
{
	Looking_Subscript();
	//system("pause");
	return 0;
}
