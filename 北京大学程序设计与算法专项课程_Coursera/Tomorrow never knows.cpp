#include <iostream>
#include <string> //法1需要
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct date {
	int yyyy, mm, dd;
};

date input_today_date()
{
	//法1，通过C++中的string类进行字符串和数字间的转换
	/*date a;
	char input[15] = { '\0' };//e.g., 2014-08-02
	char* p = input;
	cin >> input;
	a.yyyy = stoi(input);
	a.mm = stoi(&(input[5]));
	a.dd = stoi(&(input[8]));
	return a;*/

	//法2，通过getchar()吃掉"-"字符
	date a;
	cin >> a.yyyy;
	getchar();
	cin >> a.mm;
	getchar();
	cin >> a.dd;
	return a;
}

date process(date today)
{
	date next_day = today;
	if (today.mm == 12 && today.dd == 31)
	{
		next_day.yyyy++;
		next_day.mm = 1;
		next_day.dd = 1;
	}
	else if ((today.mm == 1 || today.mm == 3 || today.mm == 5 || today.mm == 7 || today.mm == 8 || today.mm == 10 || today.mm == 12) && (today.dd == 31))
	{
		next_day.mm++;
		next_day.dd = 1;
	}
	else if ((today.mm == 4 || today.mm == 6 || today.mm == 9 || today.mm == 11) && (today.dd == 30))
	{
		next_day.mm++;
		next_day.dd = 1;
	}
	else if (today.mm == 2 && ((today.yyyy % 4 == 0 && today.yyyy % 100 != 0) || today.yyyy % 400 == 0) && today.dd == 29) //today.yyyy is leap year(闰年)
	{
		next_day.mm++;
		next_day.dd = 1;
	}
	else if (today.mm == 2 && !((today.yyyy % 4 == 0 && today.yyyy % 100 != 0) || today.yyyy % 400 == 0) && today.dd == 28) //today.yyyy is common year(平年)
	{
		next_day.mm++;
		next_day.dd = 1;
	}
	else next_day.dd++;

	return next_day;
}

int main()
{
	date today, next_day;

	/*input*/
	today = input_today_date();

	/*process*/
	next_day = process(today);

	/*output*/
	cout << next_day.yyyy << "-" << setfill('0') << setw(2) << next_day.mm << "-" << setfill('0') << setw(2) << next_day.dd << endl;
	
	return 0;
}