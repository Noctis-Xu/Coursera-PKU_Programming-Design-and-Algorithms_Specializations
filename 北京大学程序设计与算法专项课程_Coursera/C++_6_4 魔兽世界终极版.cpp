/*
����
ħ������������Ǻ�ħ����˾�����������ħ����˾�������˾�֮�����������е����ɳ��У����д��������α��Ϊ1,2,3 .... N ( N <= 20 )����ħ����˾��������Ϊ0�ĳ��У���ħ����˾��������ΪN+1�ĳ��С�˾�������Ԫ������������ʿ��
������˾�����������ʿ����ʿһ���� dragon ��ninja��iceman��lion��wolf ���֡�ÿ����ʿ���б�š�����ֵ�����������������ԡ�
˫������ʿ��Ŷ��Ǵ�1��ʼ���㡣�췽��������ĵ� n ����ʿ����ž���n��ͬ����������������ĵ� n ����ʿ�����Ҳ��n��
��ʿ�ڸս�����ʱ����һ����ʼ������ֵ������ֵ��ս���лᷢ���仯���������ֵ���ٵ�0������ֵ��Ϊ����ʱӦ������Ϊ0����������ʿ��������ʧ����
�е���ʿ����ӵ�����������������֣�sword, bomb,��arrow����ŷֱ�Ϊ0,1,2��
��ʿ������ͳ��Է�˾��ߣ��ھ����ĳ�������������ˣ�ͬһʱ��ÿ���������ֻ������1������ʿ��һ������ʿ�����ͻᷢ��ս����ÿ��ս��ֻ��һ��������������һ�Ρ�������������ֵ���ȥ�����ߵĹ�����ֵ�ͽ���������sword�Ĺ�����ֵ������������û�����ͻᷢ�𷴻����������ߵ�����ֵҪ��ȥ�����߹�����ֵ��һ��(ȥβȡ��)�ͷ���������sword�Ĺ�����ֵ�����������µ��������ء�
�����ʿ��ս����ɱ�����ˣ���������������ɱ�����Ƿ���ɱ����������˾����������䷢��8������Ԫ��Ϊ������ʹ������ֵ����8����Ȼǰ����˾�����8������Ԫ�����˾�������Ԫ�����Խ������е���ʿ�������Ƚ�������з�˾�������ʿ��
���ĳ��ʿ��ĳ���е�ս����ɱ���˵��ˣ������ʿ��˾�����ȡ�øó��������е�����Ԫ��ע�⣬˾����������ȫ������������Ȼ��ſ�ʼ�Ӹ�������ʤ�̵ĳ��л�������Ԫ��������˾�����Ԫ������첻����������ʿ��˾�Ҳ������ȡ��ս��Ʒ����Ԫ��Ϊ�䲹��������
���һ��ս���Ľ����˫�����Ҵ�(ƽ��)����˫�����������߷���ս���ĳ��е�����Ԫ��
���п��Բ����ӣ�һ��ʼ���г��ж�û�����ӡ��ڲ����ĳ��У��Լ����Ϊ������������У��ɺ���ʿ��������������ڲ�����ĳ��У��Լ����Ϊż����������У�������ʿ�������������
��ĳ����������������ս������ͬһ������ʿɱ������(����ս��֮����������ɸ�ս��ʱ�̲�û�з���ս������������ս����Ȼ���������ģ�������м���ƽ�ֵ�ս�����Ͳ���������) ����ô�ó��оͻ����ʤ�������ģ���ԭ�����Űܷ������ģ���ܷ��������¡�����һ�����ϣ���һֱ���ţ�ֱ�������˸�����һ���������ֻ�ܲ�һ�����ģ�����û�����˸���ǰ��Ҳ�����ٴβ�ͬ��ɫ���졣
�������������ص㣺
sword�����ĳ�ʼ������Ϊӵ��������ʿ�Ĺ�������20%��ȥβȡ����������swordÿ����һ��ս��(�����������������Ƿ���)���ͻ��ۣ���������Ϊ����ս��ǰ��80% (ȥβȡ��)��sword��������Ϊ0ʱ����Ϊ��ʿʧȥ��sword�������ʿ����ʱ�õ���һ����ʼ������Ϊ0��sword������Ϊ��ʿû��sword.
arrow��һ��������ֵR�������һ��Ҫ�ߵ��ĳ����е��ˣ���ôӵ��arrow����ʿ�ͻ�ż�������һ�����еĵ��ˣ����ܹ����Է�˾���ĵ��ˣ�������������arrowʹ���˵�����ֵ����R��������С�ڵ���0������˱�ɱ����arrowʹ��3�κ󼴱��ľ�����ʿʧȥarrow���������ڵ���ʿ����ͬʱ�ż��ѶԷ�������
ӵ��bomb����ʿ����ս����ʼǰ����ж��Լ�����ɱ�������������������ˣ����߱������������������ܵ����Լ���ɱ�������Ҽ�����ʿ����֪�����˵Ĺ�����������ֵ������ô�ͻ�ʹ��bomb�͵���ͬ���ھ�����ʿ��Ԥ��Է��Ƿ��ʹ��bomb��
��ʿʹ��bomb�͵���ͬ���ھ�������£�������һ��ս����˫�����������߳��е�����Ԫ��Ҳ��Ӱ����е����ġ�
��ͬ����ʿ�в�ͬ���ص㡣
dragon����ӵ��һ�����������Ϊn��dragon����ʱ����ñ��Ϊ n%3 ��������dragon���С�ʿ����������ԣ��Ǹ�����������ֵΪ����������˾�ʣ������Ԫ������������dragon���������Ԫ������dragon ��һ����������������ս�������������û��ս��������ʿ��ֵ����0.8���ͻỶ����dragonÿȡ��һ��ս����ʤ��(���˱�ɱ��)��ʿ���ͻ�����0.2��ÿ����һ��δ�ܻ�ʤ��ս����ʿ��ֵ�ͻ����0.2��ʿ�����������ڻ���֮ǰ��
ninjia����ӵ���������������Ϊn��ninjia����ʱ����ñ��Ϊ n%3 �� (n+1)%3��������ninja ������Ҳ�Ӳ��������ˡ�
iceman��һ�����������Ϊn��iceman����ʱ����ñ��Ϊ n%3 ��������iceman ÿǰ���������ڵ�2����ɵ�ʱ������ֵ�����9��������������20������������ֵ��9���С�ڵ���0��������ֵ����9,���Ǳ�Ϊ1����iceman�������߶��˶�����
lion �С��ҳ϶ȡ�������ԣ����ʼֵ����������֮����˾�ʣ������Ԫ����Ŀ��ÿ����һ��δ��ɱ�����˵�ս�����ҳ϶Ⱦͽ���K���ҳ϶Ƚ���0��0���£����lion����ս��,��Զ��ʧ�������Ѿ��������˾���lion�������ܡ�Lion�ڼ���˾��������ܡ�lion ����ս��������ս��ǰ������ֵ�ͻ�ת�Ƶ��������ϡ���ν��ս��ǰ��������ÿ��Сʱ��40��ǰ��һ˲�䡣
wolf����ʱû��������������ս���������ʤ��ɱ�����ˣ����ͻ�ɻ���˵����������Լ����е������Ͳ��ɻ��ˡ����ɻ��������Ȼ�������µģ��Ѿ����õ�ʲô���ˣ�����ʲô���ġ�
�����ǲ�ͬʱ��ᷢ���Ĳ�ͬ�¼���
��ÿ�����㣬��ÿ��Сʱ�ĵ�0�֣� ˫����˾��и���һ����ʿ������
�췽˾����� iceman��lion��wolf��ninja��dragon ��˳��������ʿ��
����˾����� lion��dragon��ninja��iceman��wolf ��˳��������ʿ��
������ʿ��Ҫ����Ԫ��
����һ����ʼ����ֵΪ m ����ʿ��˾��е�����Ԫ��Ҫ���� m ����
���˾��е�����Ԫ����������ĳ��ʿ����ô˾��͵ȴ���ֱ������㹻����Ԫ��ĵ�һ�����㣬���������ʿ�����磬��2:00���췽˾���������һ�� wolf �������ʱ����Ԫ���㣬��ô�ͻ�ȴ���ֱ������Ԫ�㹻�����һ�����㣬������һ�� wolf��
��ÿ��Сʱ�ĵ�5�֣������ܵ�lion������һʱ�������ˡ�
��ÿ��Сʱ�ĵ�10�֣����е���ʿ������˾�����ǰ��һ�������Ӽ���˾��ߵ����ڳ��У����һ�������ߵ���һ�����С���Ӻ͵о�˾����ڵĳ��е���о�˾���
��ÿ��Сʱ�ĵ�20�֣�ÿ�����в���10������Ԫ������Ԫ���ڳ��У�ֱ������ʿȡ�ߡ�
��ÿ��Сʱ�ĵ�30�֣����ĳ��������ֻ��һ����ʿ����ô����ʿȡ�߸ó����е���������Ԫ������������Щ����Ԫ���͵���������˾���
��ÿ��Сʱ�ĵ�35�֣�ӵ��arrow����ʿ�ż����Ե�������˺����ż��¼�Ӧ�㷢���ڼ������ĳ��С�ע�⣬�ż�������ս������˷ż�����ʿ����õ��κκô�����ʿ��û�е��˵ĳ��б�������Ҳ��Ӱ�������ڳ��е����ĸ��������
��ÿ��Сʱ�ĵ�38�֣�ӵ��bomb����ʿ�����Ƿ�Ӧ��ʹ��bomb������ǣ�����bomb�͵���ͬ���ھ���
��ÿ��Сʱ�ĵ�40�֣�����������ʿ�ĳ��У��ᷢ��ս���� ���������5����ǰ�Ѿ���������arrow��������ô��Ȼ��Ϊ������һ��ս�������Ҵ������Ϊ�����ս����ʤ����������²����С���ʿ����������������ʿ������������ʿս�������¼���������ս��ʤ����Ӧ�÷��������鶼�ᷢ������Wolfһ���ܽɻ�����������Ҳ���ܸ������ȵȡ��ڴ������,Dragonͬ����ͨ���ж��Ƿ�Ӧ���ֵ��Լ����������������Ƿ񻶺���
��ÿ��Сʱ�ĵ�50�֣�˾�������ӵ�е�����Ԫ������
��ÿ��Сʱ�ĵ�55�֣�ÿ����ʿ������ӵ�е����������
��ʿ����Է�˾��������������ˣ��Ӵ˾ʹ��������������¡�
�κ�һ����˾������ǳ�����2�����ˣ�����Ϊ��˾��ѱ�����ռ�졣
�κ�һ����˾�������ռ�죬��ս��������ս������֮��Ͳ��ᷢ���κ������ˡ�
����һ��ʱ�䣬Ҫ���㽫��0��0�ֿ�ʼ����ʱ��Ϊֹ�������¼���˳��������¼������Ӧ������������£�
1) ��ʿ����
��������� 000:00 blue lion 1 born
��ʾ�� 0��0�֣����Ϊ1����ħlion��ʿ����
����������dragon����ô��Ҫ�����һ�У�����
000:00 blue dragon 1 born
Its morale is 23.34
��ʾ�ø�dragon����ʱʿ����23. 34(�������뵽С�������λ)
����������lion����ô��Ҫ�����һ�У���:
000:00 blue lion 1 born
Its loyalty is 24
��ʾ��lion����ʱ���ҳ϶���24
2) lion����
��������� 000:05 blue lion 1 ran away
��ʾ�� 0��5�֣����Ϊ1����ħlion��ʿ����
3) ��ʿǰ����ĳһ����
��������� 000:10 red iceman 1 marched to city 1 with 20 elements and force 30
��ʾ�� 0��10�֣���ħ1����ʿicemanǰ����1�ų��У���ʱ������ֵΪ20,������Ϊ30
����iceman,���������ֵ�͹�����Ӧ���Ǳ仯�����ֵ
4)��ʿ�ż�
��������� 000:35 blue dragon 1 shot
��ʾ�� 0��35�֣����Ϊ1����ħdragon��ʿ���һ֧�����������ļ�ɱ���˵��ˣ���Ӧ���������
000:35 blue dragon 1 shot and killed red lion 4
��ʾ�� 0��35�֣����Ϊ1����ħdragon��ʿ���һ֧����ɱ���˱��Ϊ4�ĺ�ħlion��
5)��ʿʹ��bomb
��������� 000:38 blue dragon 1 used a bomb and killed red lion 7
��ʾ�� 0��38�֣����Ϊ1����ħdragon��ʿ��ը���ͱ��Ϊ7�ĺ�ħlionͬ���ھ���
6) ��ʿ��������
���������000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30
��ʾ��0��40�֣�1�ų����У���ħ1����ʿiceman ������ħ1����ʿlion,�ڷ������ǰ����ħ1����ʿiceman����ֵΪ20��������Ϊ 30
7) ��ʿ����
���������001:40 blue dragon 2 fought back against red lion 2 in city 1
��ʾ��1��40�֣�1�ų����У���ħ2����ʿdragon������ħ2����ʿlion
8) ��ʿս��
���������001:40 red lion 2 was killed in city 1
������������ʿ�Ͳ�������һ�������
9) ��ʿ����
���������003:40 blue dragon 2 yelled in city 4
10) ��ʿ��ȡ����Ԫ( elements )
���������001:40 blue dragon 2 earned 10 elements for his headquarter
11) ��������
���������004:40 blue flag raised in city 4
12) ��ʿ�ִ�о�˾�
���������001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
(��ʱ������ֵΪ20,������Ϊ30������iceman,���������ֵ�͹�����Ӧ���Ǳ仯�����ֵ
13) ˾���ռ��
���������003:10 blue headquarter was taken
14)˾���������Ԫ����
000:50 100 elements in red headquarter
000:50 120 elements in blue headquarter
��ʾ��0��50�֣��췽˾���100������Ԫ��������120��
15)��ʿ�����������
000:55 blue wolf 2 has arrow(2),bomb,sword(23)
000:55 blue wolf 4 has no weapon
000:55 blue wolf 5 has sword(20)
��ʾ��0��55�֣���ħ2����ʿwolf��һ֧arrow����֧arrow��������2�Σ���һ��bomb������һ֧������Ϊ23��sword��
��ħ4����ʿwolfû������
��ħ5����ʿwolf��һ֧������Ϊ20��sword��
�����������ʱ�����������ǣ�arrow,bomb,sword�����û��ĳ��������ĳ�������Ͳ����ᡣ����ʱ���Ȱ������򶫵�˳�����еĺ���ʿ���棬Ȼ���ٴ��������е�����ʿ���档
����¼�ʱ��
���Ȱ�ʱ��˳�������
ͬһʱ�䷢�����¼����������ص�������������. ��ʿǰ�����¼�, ���Ƿ�����Ŀ�ĵء�
��һ��ս�����п��ܷ�������� 6 �� 11 ���¼�����Щ�¼�����ͬʱ��������ʱ�����ս����ʼʱ�䡣һ��ս���е���Щ�¼������С��Ӧ���������
������ʿͬʱ�ִ�ͬһ���У������������ʿ��ǰ���¼������������ʿ�ġ�
��Ȼ��13���¼�����֮ǰ��һ˲��һ��������12���¼������ʱ������������ͬһʱ�䷢��������Ӧ�����12���¼�
��Ȼ�κ�һ����˾���ռ��֮�󣬾Ͳ������κ����鷢���ˡ�����˾���ռ��ͬʱ�������¼���ȫ��Ҫ�����
����
��һ����t,���������������
ÿ�����������С�
��һ�У�������� M,N,R,K, T���京��Ϊ��
ÿ��˾�һ��ʼ����M������Ԫ( 1 <= M <= 10000)
����˾�֮��һ����N������( 1 <= N <= 20 )
arrow�Ĺ�������R
lionÿ����һ��δ��ɱ�����˵�ս�����ҳ϶Ⱦͽ���K��
Ҫ�������0ʱ0�ֿ�ʼ����ʱ��TΪֹ(����T) �������¼���T�Է���Ϊ��λ��0 <= T <= 5000
�ڶ��У���������������� dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ�����Ƕ�����0С�ڵ���10000
�����У���������������� dragon ��ninja��iceman��lion��wolf �Ĺ����������Ƕ�����0С�ڵ���10000
���
��ÿ�����ݣ������һ�У�
Case n:
��Ե�һ�����ݾ���� Case1:
Ȼ��ǡ����˳��͸�ʽ�����ʱ��TΪֹ�����������¼���ÿ���¼������¼�������ʱ�俪ͷ��ʱ���ʽ�ǡ�ʱ: �֡�����ʱ������λ�����֡�����λ��

��������
1
20 1 10 10 1000
20 20 30 10 20
5 5 5 5 5

�������
Case 1:
000:00 blue lion 1 born
Its loyalty is 10
000:10 blue lion 1 marched to city 1 with 10 elements and force 5
000:30 blue lion 1 earned 10 elements for his headquarter
000:50 20 elements in red headquarter
000:50 20 elements in blue headquarter
000:55 blue lion 1 has no weapon
001:00 blue dragon 2 born
Its morale is 0.00001:10 blue lion 1 reached red headquarter with 10 elements and force 5
001:10 blue dragon 2 marched to city 1 with 20 elements and force 5
001:30 blue dragon 2 earned 10 elements for his headquarter
001:50 20 elements in red headquarter
001:50 10 elements in blue headquarter
001:55 blue lion 1 has no weapon
001:55 blue dragon 2 has arrow(3)
002:10 blue dragon 2 reached red headquarter with 20 elements and force 5
002:10 red headquarter was taken
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
			p->morale = (double)HP / p->warrior_cost;
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