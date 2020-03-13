// Calendar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calendar(int a)
{
	int YYYY = 2000, MM = 1, DD = 1, DayOfWeek = 6, today = a + 1;//today是逝去的天数加上1，表示当前天数
	//计算year
	while (today > 365)
	{
		if (YYYY % 100 == 0 && YYYY % 400 != 0)
		{
			today = today - 365;
			YYYY++;
		}
		else if (today > 366)
		{
			today = today - 366;
			YYYY++;
		}
		else return YYYY;
		for (int i = 3; i > 0; i--)
		{
			if (today > 365)
			{
				today = today - 365;
				YYYY++;
			}
			else break;
		}
	}
	return YYYY;
}

int main()
{
	int day = 0, yyyy = 0;
	while (1)
	{
		cin >> day;
		yyyy = calendar(day);
		cout << yyyy << '\n';
	}

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
