#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <string.h> //strlenº¯Êý

using namespace std;

struct patient {
	char number[4];
	float level;
};

int main() {
	int count;
	float criteria;
	cin >> count >> criteria;
	patient patients[50];
	for (int i = 0; i < count; i++) {
		cin >> patients[i].number >> patients[i].level;
	}

	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - 1 - i; j++) {
			if (patients[j].level < patients[j + 1].level) {
				patient temp = patients[j];
				patients[j] = patients[j + 1];
				patients[j + 1] = temp;
			}
		}
	}
	
	int flag = 0;
	for (int i = 0; i < count; i++) {
		if (patients[i].level >= criteria) {
			printf("%s %0.1f\n", patients[i].number, patients[i].level);
			flag++;
		}
	}
	if (flag == 0) {
		cout << "None." << endl;
	}

	return 0;
}