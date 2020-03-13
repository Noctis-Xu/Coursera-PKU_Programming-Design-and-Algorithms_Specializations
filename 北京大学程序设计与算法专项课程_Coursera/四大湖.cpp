#include<iostream>
using namespace std;

void solution() 
{
	int BoyangLake, DongtingLake, TaiLake, HongzeLake;
	for (BoyangLake = 1; BoyangLake <= 4; BoyangLake++)
	{
		for (DongtingLake = 1; DongtingLake <= 4; DongtingLake++)
		{
			if (DongtingLake == BoyangLake)
				continue;
			for (TaiLake = 1; TaiLake <= 4; TaiLake++)
			{
				if (TaiLake == BoyangLake || TaiLake == DongtingLake)
					continue;
				for (HongzeLake = 1; HongzeLake <= 4; HongzeLake++)
				{
					if(HongzeLake == BoyangLake || HongzeLake == DongtingLake || HongzeLake == TaiLake)
						continue;
					if ((DongtingLake == 1 && HongzeLake != 4 && BoyangLake != 3) || (DongtingLake != 1 && HongzeLake == 4 && BoyangLake != 3) || (DongtingLake != 1 && HongzeLake != 4 && BoyangLake == 3))
					{
						if ((HongzeLake == 1 && DongtingLake != 4 && BoyangLake != 2 && TaiLake != 3) || (HongzeLake != 1 && DongtingLake == 4 && BoyangLake != 2 && TaiLake != 3) || (HongzeLake != 1 && DongtingLake != 4 && BoyangLake == 2 && TaiLake != 3) || (HongzeLake != 1 && DongtingLake != 4 && BoyangLake != 2 && TaiLake == 3))
						{
							if ((HongzeLake == 4 && DongtingLake != 3) || (HongzeLake != 4 && DongtingLake == 3))
							{
								if((BoyangLake==1&&TaiLake!=4&&HongzeLake!=2&&DongtingLake!=3)||(BoyangLake != 1 && TaiLake == 4 && HongzeLake != 2 && DongtingLake != 3)||(BoyangLake != 1 && TaiLake != 4 && HongzeLake == 2 && DongtingLake != 3)||(BoyangLake != 1 && TaiLake != 4 && HongzeLake != 2 && DongtingLake == 3))
									cout << BoyangLake << endl << DongtingLake << endl << TaiLake << endl << HongzeLake << endl;
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
	solution();
	return 0;
}