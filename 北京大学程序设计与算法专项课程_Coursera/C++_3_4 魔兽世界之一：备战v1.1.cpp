/*�Ѳ�ͬ����ʿ������Ҫ���ĵ�cost��Ϊ��������Headquater.warrior_count[5]��
��ͬ��Headquater����cost��˳��һ�����Դ�������ͬHeadquater����ʿ����˳��ͬ
���磺
cost: dragon = 1, ninja=2, iceman=3, lion=4, wolf=5
Red Headquater.warrior_cost(1,2,3,4,5���������˳��Ϊdragon = 1, ninja=2, iceman=3, lion=4, wolf=5
Blue Headquater.warrior_cost(2,1,3,4,5���������˳��Ϊninja=2, dragon = 1, iceman=3, lion=4, wolf=5
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Warriors {
	char species[10];
	int n;
	int warrior_count = 0;//��ͬ����Ӫ��ͬ��count���飬��������ʿ����˳���count��������
	int warrior_cost;//��ͬ����Ӫ��ͬ��cost���飬��������ʿ����˳���cost��������
};

class Headquarter {
private:
	Warriors warriors[5];//�ֱ����5�����͵�սʿ���Ե��ܼƣ���������˳�����սʿ����˳��
	char Name[10];//red or blue
	int HP;
	//bool HP_flag = true;//true��ʾ��������սʿ
	Warriors* p_wr = &warriors[0];
public:
	Headquarter(const char* name, int hp, const char* spec0, const char* spec1, const char* spec2, const char* spec3, const char* spec4, int cost0, int cost1, int cost2, int cost3, int cost4) {
		strcpy(Name, name);
		HP = hp;
		strcpy(warriors[0].species, spec0);
		strcpy(warriors[1].species, spec1);
		strcpy(warriors[2].species, spec2);
		strcpy(warriors[3].species, spec3);
		strcpy(warriors[4].species, spec4);
		warriors[0].warrior_cost = cost0;
		warriors[1].warrior_cost = cost1;
		warriors[2].warrior_cost = cost2;
		warriors[3].warrior_cost = cost3;
		warriors[4].warrior_cost = cost4;
	}
	bool construct_warrior(int time) {//����ֵfalse��ʾ��������ʿ����true��ʾ����ɹ�
		int no = time + 1;//��ŵ��ڵ�ǰtime+1
		
		for (int i = 0; i < 5; i++) {
			if (HP >= p_wr->warrior_cost) {
				(p_wr->warrior_count)++;
				HP -= p_wr->warrior_cost;
				printf("%03d ", time);
				printf("%s %s %d born with strength %d,%d %s in %s headquarter\n", Name, p_wr->species, no, p_wr->warrior_cost, p_wr->warrior_count, p_wr->species, Name);
				if (p_wr == &warriors[4]) {//ָ�뵽������ĩβ��ָ�����
					p_wr = &warriors[0];
				}
				else p_wr++;//ָ�����
				return true;
			}
			if (p_wr == &warriors[4]) {//ָ�뵽������ĩβ��ָ�����
				p_wr = &warriors[0];
			}
			else p_wr++;//ָ�����
		}
		//�����������ʿ�����Ҳû���˳�������������Ѿ����������ˣ�����ִ�������ֹͣ�������
		printf("%03d ", time);
		printf("%s headquarter stops making warriors\n", Name);
		return false;

	}
};


int main() {
	//red: 0:iceman��1:lion��2:wolf��3:ninja��4:dragon
	//blue: 0:lion��1:dragon��2:ninja��3:iceman��4:wolf
	int cases, hp;
	cin >> cases;
	int cost[5];//0:dragon��1:ninja��2:iceman��3:lion��4:wolf

	for (int c = 1; c <= cases; c++) {//casesѭ��
		cin >> hp;
		for (int i = 0; i < 5; i++) {
			cin >> cost[i];
		}

		Headquarter red("red", hp, "iceman", "lion", "wolf", "ninja", "dragon", cost[2], cost[3], cost[4], cost[1], cost[0]);//red: 0:iceman��1:lion��2:wolf��3:ninja��4:dragon
		Headquarter blue("blue", hp, "lion", "dragon", "ninja", "iceman", "wolf", cost[3], cost[0], cost[1], cost[2], cost[4]);//blue: 0:lion��1:dragon��2:ninja��3:iceman��4:wolf

		bool red_bool = true, blue_bool = true;
		cout << "Case:" << c << endl;
		for (int time = 0; red_bool || blue_bool; time++) {
			if (red_bool) {
				red_bool = red.construct_warrior(time);//red: 0:iceman��1:lion��2:wolf��3:ninja��4:dragon
			}
			if (blue_bool) {
				blue_bool = blue.construct_warrior(time);//blue: 0:lion��1:dragon��2:ninja��3:iceman��4:wolf
			}
		}
	}

	return 0;
}