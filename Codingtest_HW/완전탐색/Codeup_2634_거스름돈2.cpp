
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int money;
int n;
int mon[11];
int min_Cnt = 0x7fffffff;

// ¿ÏÀü Å½»ö
void f(int remain_cost, int crt_Cnt)
{
	//cout << remain_cost << " " << crt_Cnt << "\n";

	if (remain_cost < 0) return;
	else if (remain_cost == 0)
	{
		if (min_Cnt > crt_Cnt)
		{
			min_Cnt = crt_Cnt;
		}
		return;
	}		

	for (int i = 1; i <= n; i++)
	{
		if (remain_cost - mon[i] >= 0)
		{
			f(remain_cost - mon[i], crt_Cnt + 1);
		}		
	}
}

int f2(int remain_cost, int crt_Cnt)
{
	//cout << remain_cost << " " << crt_Cnt << "\n";

	if (remain_cost < 0) return;
	else if (remain_cost == 0)
	{
		if (min_Cnt > crt_Cnt)
		{
			min_Cnt = crt_Cnt;			
		}
		return (min_Cnt-crt_Cnt);
	}

	for (int i = 1; i <= n; i++)
	{
		if (remain_cost - mon[i] >= 0)
		{
			f(remain_cost - mon[i], crt_Cnt + 1);
		}
	}
	return 0;
}


int main()
{
	cin >> money;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> mon[i];
	}

	cout <<f2(money, 0);
	cout << min_Cnt;
	return 0;
}