/*
����
ħ������������Ǻ�ħ����˾�����������ħ����˾�������˾�֮�����������е����ɳ��С�
��˾���City 1��City 2��������City n����˾�

������˾�����������ʿ����ʿһ���� dragon ��ninja��iceman��lion��wolf ���֡�ÿ����ʿ���б�š�����ֵ���������ԡ�

�е���ʿ����ӵ�����������������֣�sword, bomb,��arrow����ŷֱ�Ϊ0,1,2��

˫������ʿ��Ŷ��Ǵ�1��ʼ���㡣�췽��������ĵ� n ����ʿ����ž���n��ͬ����������������ĵ� n ����ʿ�����Ҳ��n��

��ͬ����ʿ�в�ͬ���ص㡣

dragon ����ӵ��һ�����������Ϊn��dragon����ʱ����ñ��Ϊ n%3 ��������dragon���С�ʿ����������ԣ��Ǹ�����������ֵΪ����������˾�ʣ������Ԫ������������dragon���������Ԫ������

ninjia����ӵ���������������Ϊn��ninjia����ʱ����ñ��Ϊ n%3 �� (n+1)%3��������

iceman��һ�����������Ϊn��iceman����ʱ����ñ��Ϊ n%3 ��������

lion �С��ҳ϶ȡ�������ԣ���ֵ��������������˾�ʣ������Ԫ����Ŀ��

wolfû�ص㡣

��ע�⣬���Ժ����Ŀ���ʿ��ʿ��������ֵ���ҳ϶����������ڼ䶼���ܷ����仯���������ã���ʿ���е���������ʹ�ù�����Ҳ�ᷢ���仯��

��ʿ�ڸս�����ʱ����һ������ֵ��

��ÿ�����㣬˫����˾��и���һ����ʿ������

�췽˾����� iceman��lion��wolf��ninja��dragon ��˳��ѭ��������ʿ��

����˾����� lion��dragon��ninja��iceman��wolf ��˳��ѭ��������ʿ��

������ʿ��Ҫ����Ԫ��

����һ����ʼ����ֵΪ m ����ʿ��˾��е�����Ԫ��Ҫ���� m ����

���˾��е�����Ԫ����������ĳ����˳��Ӧ���������ʿ����ô˾�����ͼ������һ�������������ʿ�����������ˣ���˾�ֹͣ������ʿ��

����һ��ʱ�䣬��˫��˾��ĳ�ʼ����Ԫ��Ŀ��Ҫ���㽫��0��0�ֿ�ʼ��˫��˾�ֹͣ������ʿΪֹ�������¼���˳�������

һ���������¼������Ӧ������������£�

1) ��ʿ����

��������� 004 blue lion 5 born with strength 5,2 lion in red headquarter

��ʾ�� 4���������Ϊ5����ħlion��ʿ������������ʱ����ֵΪ5,��������ħ˾��ﹲ��2��lion��ʿ��(Ϊ������������ǵ��ʵĸ�����ʽ)ע�⣬ÿ�����һ���µ���ʿ����Ҫ�����ʱ˾��ﹲ�ж��ٸ�������ʿ��

����������dragon����ô��Ҫ���һ�У�����

It has a arrow,and it's morale is 23.34

��ʾ��dragon����ʱ�õ���arrow,��ʿ����23.34��Ϊ�������������arrowǰ��Ĺڴ���a,����an��ʿ����ȷ��С�������2λ���������룩

����������ninjia����ô��Ҫ���һ�У�����

It has a bomb and a arrow

��ʾ��ninjia����ʱ�õ���bomb��arrow��

����������iceman����ô��Ҫ���һ�У�����

It has a sword

��ʾ��iceman����ʱ�õ���sword��

����������lion����ô��Ҫ���һ�У�����

It's loyalty is 24

��ʾ��lion����ʱ���ҳ϶���24��

2) ˾�ֹͣ������ʿ

��������� 010 red headquarter stops making warriors

��ʾ�� 10�������췽˾�ֹͣ������ʿ

����¼�ʱ��

���Ȱ�ʱ��˳�������

ͬһʱ�䷢�����¼����������˾��ģ��������˾��ġ�

����
��һ����һ������,�����������������
ÿ��������ݹ����С�
��һ�У�һ������M���京��Ϊ�� ÿ��˾�һ��ʼ����M������Ԫ( 1 <= M <= 10000)
�ڶ��У���������������� dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ�����Ƕ�����0С�ڵ���10000

���
��ÿ��������ݣ�Ҫ�������0ʱ0�ֿ�ʼ����˫��˾���ֹͣ������ʿΪֹ�������¼���
��ÿ��������ݣ����������Case:n" n�ǲ������ݵı�ţ���1��ʼ
��������ǡ����˳��͸�ʽ��������¼���ÿ���¼������¼�������ʱ�俪ͷ��ʱ����СʱΪ��λ������λ��


��������
1
20
3 4 5 6 7

�������
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cstdlib>


using namespace std;

struct Warriors {//����������һ��ͬ���͵�ʿ����������1��ʿ��
	char species[10];//ĳ���͵�ʿ����
	//int n;//���
	char weapons[2][10] = { {'\0'},{'\0'} };//���ӵ��2������
	float morale;//ʿ��
	int loyalty;//�ҳ�
	int warrior_count = 0;//��ͬ����Ӫ��ͬ��count���飬��������ʿ����˳���count��������
	int warrior_cost;//��ͬ����Ӫ��ͬ��cost���飬��������ʿ����˳���cost��������
};

class Headquarter {
private:
	Warriors warriors[5];//�ֱ����5�����͵�սʿ���Ե��ܼƣ���������˳�����սʿ����˳��
	char Name[10];//red or blue
	int HP;
	Warriors* p_wr = &warriors[0];
	void equip_weapon(Warriors* p, int No) {
		//sword, bomb, ��arrow����ŷֱ�Ϊ0, 1, 2��
		//dragon ����ӵ��һ�����������Ϊn��dragon����ʱ����ñ��Ϊ n % 3 ��������dragon���С�ʿ����������ԣ��Ǹ�����������ֵΪ����������˾�ʣ������Ԫ������������dragon���������Ԫ������
		//ninjia����ӵ���������������Ϊn��ninjia����ʱ����ñ��Ϊ n % 3 ��(n + 1) % 3��������
		//iceman��һ�����������Ϊn��iceman����ʱ����ñ��Ϊ n % 3 ��������
		//lion �С��ҳ϶ȡ�������ԣ���ֵ��������������˾�ʣ������Ԫ����Ŀ��
		//wolfû�ص㡣
		if (strcmp(p->species, "dragon") == 0) {
			switch (No % 3) {
			case 0:strcpy(p->weapons[0], "sword"); break;
			case 1:strcpy(p->weapons[0], "bomb"); break;
			case 2:strcpy(p->weapons[0], "arrow"); break;
			}
			p->morale = (double)HP/ p->warrior_cost;
			printf("It has a %s,and it's morale is %.2f\n", p->weapons[0], p->morale);
		}
		else if (strcmp(p->species, "ninja") == 0) {
			switch (No % 3) {
			case 0:strcpy(p->weapons[0], "sword"); strcpy(p->weapons[1], "bomb"); break;
			case 1:strcpy(p->weapons[0], "bomb"); strcpy(p->weapons[1], "arrow"); break;
			case 2:strcpy(p->weapons[0], "arrow"); strcpy(p->weapons[1], "sword"); break;
			}
			printf("It has a %s and a %s\n", p->weapons[0], p->weapons[1]);
		}
		else if (strcmp(p->species, "iceman") == 0) {
			switch (No % 3) {
			case 0:strcpy(p->weapons[0], "sword");  break;
			case 1:strcpy(p->weapons[0], "bomb");  break;
			case 2:strcpy(p->weapons[0], "arrow");  break;
			}
			printf("It has a %s\n", p->weapons[0]);
		}
		else if (strcmp(p->species, "lion") == 0) {
			p->loyalty = HP;
			printf("It's loyalty is %d\n", p->loyalty);
		}
		else if (strcmp(p->species, "wolf") == 0) {}
	}

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
				equip_weapon(p_wr, no);
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

		bool red_bool = true, blue_bool = true;//Ϊfalseʱֹͣ����ʿ��
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