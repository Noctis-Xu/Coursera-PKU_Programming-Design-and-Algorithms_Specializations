#include <iostream>
#include <string.h>

using namespace std;

class Warrior {
private:
	char Species[10]; //0:dragon、1:ninja、2:iceman、3:lion、4:wolf
	int No;
	int Strength;
	int Attack = 0;
	friend class Headquarter;
public:
	Warrior(char* str, int no, int strength) :Strength(strength), No(no) {
		strcpy(Species, str);
	}
};

class Headquarter {
private:
	int warrior_count[5] = { 0 };//0:dragon、1:ninja、2:iceman、3:lion、4:wolf
	int HP;
	char Name[10];
public:
	static int warrior_cost[5];//0:dragon、1:ninja、2:iceman、3:lion、4:wolf
	Headquarter(char* name, int hp) {
		strcpy(Name, name);
		HP = hp;
	}
	void construct_warrior(char* species, int no, int number) {
		Warrior wr(species, no, warrior_cost[number]);
		wr;
		printf("%s %s %d born with strength %d,%d iceman in %s headquarter", Name, wr.Species, wr.No, wr.Strength, warrior_count[number], Name)

	}

};


int main() {
	int cases, hp;
	char str_red[10] = "red";
	char str_blue[10] = "blue";
	enum Species {}species;
	cin >> cases;

	for (int c = 1; c <= cases; c++) {
		cin >> hp;
		for (int i = 0; i < 5; i++) {
			cin >> Headquarter::warrior_cost[i];
		}
		Headquarter red(str_red, hp), blue(str_blue, hp);

		cout << "Case:" << c;

		for (int i = 0;; i++) {
			int number = i % 5;//代表5次里的第几次，number可能为0,1,2,3,4

			switch (species)
				//red: 0:iceman、1:lion、2:wolf、3:ninja、4:dragon
				printf("%03d ", i);
			red.construct_warrior();
			//blue: 0:lion、1:dragon、2:ninja、3:iceman、4:wolf
			printf("%03d ", i);
			blue.construct_warrior();
		}
	}


	return 0;
}