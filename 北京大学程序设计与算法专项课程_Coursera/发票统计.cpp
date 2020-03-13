// 第二周综合编程练习（1）.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Employee
{
	int ID; //1 or 2 or 3
	int amount; //no more than 100
	char category[150]; //A or B or C
	float money[150]; //no more than 1000.0
};

struct Category_SumOfMoney
{
	char category[3];
	float SumOfMoney[3];
};

void sorting(Employee* employees, int len)
{
	Employee temp;
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < len - i; j++)
		{
			if (employees[j].ID > employees[j + 1].ID)
			{
				temp = employees[j];
				employees[j] = employees[j + 1];
				employees[j + 1] = temp;
			}
		}
	}
}

float total_money(Employee employee)
{
	float sum = 0;
	for (int i = 0; i < employee.amount; i++)
	{
		sum = sum + employee.money[i];
	}
	return sum;
}

void count(Employee* employee, Category_SumOfMoney& ABC, int len) //Category_SumOfMoney& ABC是引用
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < employee[i].amount; j++)
		{
			switch (employee[i].category[j]) {
			case 'A':
				ABC.SumOfMoney[0] = ABC.SumOfMoney[0] + employee[i].money[j];
				break;
			case 'B':
				ABC.SumOfMoney[1] = ABC.SumOfMoney[1] + employee[i].money[j];
				break;
			case 'C':
				ABC.SumOfMoney[2] = ABC.SumOfMoney[2] + employee[i].money[j];
				break;
			}
		}
	}
}

int main()
{
	Employee employee[3];
	struct Category_SumOfMoney ABC = { { 'A','B','C' }, {0,0,0} };
	for (int i = 0; i < 3; i++) //data input
	{
		cin >> employee[i].ID >> employee[i].amount;
		for (int j = 1, m = 0, n = 0; getchar() != '\n'; j++)
		{
			if (j % 2 == 1)
				cin >> employee[i].category[m++];
			else
				cin >> employee[i].money[n++];
		}
	}

	//data process
	int len = sizeof(employee) / sizeof(employee[0]); //if we don't know the length of employee array
	sorting(employee, len);
	count(employee, ABC, len);

	//output processed data
	for (int i = 0; i < len; i++)
	{
		printf("%d %.2f\n", employee[i].ID, total_money(employee[i]));
	}
	for (int i = 0; i < len; i++)
	{
		printf("%c %.2f\n", ABC.category[i], ABC.SumOfMoney[i]);
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
