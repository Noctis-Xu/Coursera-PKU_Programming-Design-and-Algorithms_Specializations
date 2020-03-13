#include <iostream>
#include <stdio.h>
#include <string>


using namespace std;

int main()
{
	int arr[] = { 34,12,89,68 };
	StringBuffer sb = new StringBuffer();
	sb.append("[");
	for (int i = 0; i < arr.length; i++) {

		if (i != arr.length - 1) {

			sb.append(arr[i] + ",");

		}
		else {

			sb.append(arr[i] + "]");

		}

	}
	return sb.toString();
	

}