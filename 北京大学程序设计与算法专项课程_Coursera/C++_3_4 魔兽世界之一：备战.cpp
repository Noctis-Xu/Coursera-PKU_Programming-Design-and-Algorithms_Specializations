/*���з����ǰѲ�ͬ����ʿ������Ҫ���ĵ�cost��Ϊ��������Headquater.warrior_count[5]��
��ͬ��Headquater����cost��˳��һ�����Դ�������ͬHeadquater����ʿ����˳��ͬ
���磺
cost: dragon = 1, ninja=2, iceman=3, lion=4, wolf=5
Red Headquater.warrior_cost(1,2,3,4,5���������˳��Ϊdragon = 1, ninja=2, iceman=3, lion=4, wolf=5
Blue Headquater.warrior_cost(2,1,3,4,5���������˳��Ϊninja=2, dragon = 1, iceman=3, lion=4, wolf=5
*/

#include <iostream>
#include <string.h>

using namespace std;
enum SPECIES { dragon = 0, ninja, iceman, lion, wolf };

class Warrior {
private:
	//char Species[10]; //0:dragon��1:ninja��2:iceman��3:lion��4:wolf
	SPECIES Species; //0:dragon��1:ninja��2:iceman��3:lion��4:wolf
	int No;
	int Strength;
	int Attack = 0;
	friend class Headquarter;
public:
	Warrior(SPECIES species, int no, int strength) :Species(species), No(no), Strength(strength) {
		//strcpy(species, str);
	}
};

class Headquarter {
private:
	struct warriors
	char Name[10];//red or blue
	int HP;
	bool HP_flag = true;//true��ʾ��������սʿ
	int warrior_count[5] = { 0 };//��ͬ����Ӫ��ͬ��count���飬��������ʿ����˳���count��������
	int warrior_cost[5];//��ͬ����Ӫ��ͬ��cost���飬��������ʿ����˳���cost��������
	const int* p_cost = &warrior_cost[0]; // ������λ��ǰ��������һ��ʿ����
	int * p_count = &warrior_count[0];//������λ��ǰ��������һ��ʿ����
public:
	Headquarter(char* name, int hp, int cost0, int cost1, int cost2, int cost3, int cost4) {
		strcpy(Name, name);
		HP = hp;
		warrior_cost[0] = cost0;
		warrior_cost[1] = cost1;
		warrior_cost[2] = cost2;
		warrior_cost[3] = cost3;
		warrior_cost[4] = cost4;
	}
	bool construct_warrior(int time) {//����ֵfalse��ʾ��������ʿ����true��ʾ����ɹ�
		int no = time + 1;//��ŵ��ڵ�ǰtime+1
		const int number = time % 5;//number=0,1,2,3,4
		if (HP_flag) {
			for (int i = 0; i < 5; i++) {
				if (HP >= *p_cost) {
					(*p_count)++;
					HP -= *p_cost;
					printf("%s %s %d born with strength %d,%d iceman in %s headquarter", Name, wr.Species, wr.No, wr.Strength, warrior_count[number], Name);
				}
				if (p_cost == &warrior_cost[4]) {
					p_cost = &warrior_cost[0];
					p_count = &warrior_cost[0];
				}
				else {
					p_cost++;
					p_count++;
				}
				return true;
			}
		}
		//�����������ʿ�����Ҳû���˳�������������Ѿ����������ˣ�����ִ�������ֹͣ�������
		printf("%03d ", time);
		printf("%s headquarter stops making warriors", Name);
		HP_flag = false;
		return false;

		/*Warrior wr(species, no, warrior_cost[number]);
		switch (wr.Species) {
		case dragon:if (HP >= warrior_cost[0]) {
			warrior_count[0]++; HP -= warrior_cost[0];
		}
				   else return false;
			break;
		case ninja:if (HP >= warrior_cost[1]) {
			warrior_count[1]++; HP -= warrior_cost[1];
		}
				  else return false;
			break;
		case iceman:if (HP >= warrior_cost[2]) {
			warrior_count[2]++; HP -= warrior_cost[2];
		}
				   else return false;
			break;
		case lion:if (HP >= warrior_cost[3]) {
			warrior_count[3]++; HP -= warrior_cost[3];
		}
				 else return false;
			break;
		case wolf:if (HP >= warrior_cost[4]) {
			warrior_count[4]++; HP -= warrior_cost[4];
		}
				 else return false;
			break;
		}*/
		//printf("%s %s %d born with strength %d,%d iceman in %s headquarter", Name, wr.Species, wr.No, wr.Strength, warrior_count[number], Name);
		//return true;
	}
};


int main() {
	int cases, hp;
	char str_red[10] = "red";
	char str_blue[10] = "blue";
	cin >> cases;
	int cost[5];//0:dragon��1:ninja��2:iceman��3:lion��4:wolf

	for (int c = 1; c <= cases; c++) {//casesѭ��
		cin >> hp;
		for (int i = 0; i < 5; i++) {
			cin >> cost[i];
		}
		Headquarter red(str_red, hp, cost[2], cost[3], cost[4], cost[1], cost[0]);//red: 0:iceman��1:lion��2:wolf��3:ninja��4:dragon
		Headquarter blue(str_blue, hp, cost[3], cost[0], cost[1], cost[2], cost[4]);//blue: 0:lion��1:dragon��2:ninja��3:iceman��4:wolf

		bool red_bool = true, blue_bool = true;
		cout << "Case:" << c;
		for (int time = 0; red_bool || blue_bool; time++) {
			//printf("%03d ", time);
			red_bool = red.construct_warrior(time);//red: 0:iceman��1:lion��2:wolf��3:ninja��4:dragon
			//printf("%03d ", time);
			blue_bool = blue.construct_warrior(time);//blue: 0:lion��1:dragon��2:ninja��3:iceman��4:wolf


			//int number = i % 5;//����5����ĵڼ��Σ�number����Ϊ0,1,2,3,4

			//switch (number) {//red: 0:iceman��1:lion��2:wolf��3:ninja��4:dragon
			//case 0:printf("%03d ", i);
			//	red_bool = red.construct_warrior(iceman, i);
			//	break;
			//case 1:printf("%03d ", i);
			//	red_bool = red.construct_warrior(lion, i);
			//	break;
			//case 2:printf("%03d ", i);
			//	red_bool = red.construct_warrior(wolf, i);
			//	break;
			//case 3:printf("%03d ", i);
			//	red_bool = red.construct_warrior(ninja, i);
			//	break;
			//case 4:printf("%03d ", i);
			//	red_bool = red.construct_warrior(dragon, i);
			//	break;
			//}

			//switch (number) {//blue: 0:lion��1:dragon��2:ninja��3:iceman��4:wolf
			//case 0:printf("%03d ", i);
			//	blue_bool = blue.construct_warrior(lion, i);
			//	break;
			//case 1:printf("%03d ", i);
			//	blue_bool = blue.construct_warrior(dragon, i);
			//	break;
			//case 2:printf("%03d ", i);
			//	blue_bool = blue.construct_warrior(ninja, i);
			//	break;
			//case 3:printf("%03d ", i);
			//	blue_bool = blue.construct_warrior(iceman, i);
			//	break;
			//case 4:printf("%03d ", i);
			//	blue_bool = blue.construct_warrior(wolf, i);
			//	break;
			//}

		}


		return 0;
	}