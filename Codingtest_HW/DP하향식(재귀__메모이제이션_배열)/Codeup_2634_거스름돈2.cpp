
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int money;
int n;
int mon[11];// = 0;
int min_Cnt = 0x7fffffff;

// 완전 탐색
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

// f2: 재귀, 리턴값 있게..
int f2(int num)
{
	if (num < 0) return 0;
	if (num > money) return 0;
	for (int i = 1; i <= n; i++)
	{
		if (num == mon[i]) return 1;
	}

	int sub_min = 0x3fffffff;
	for (int i = 1; i <= n; i++)
	{
		sub_min = min(sub_min, f2(num - mon[i]));
	}

	return sub_min + 1;
}


//DP 하향식: 재귀+메모이제이션(배열) 
// coinChange: 재귀 + 메모이제이션으로..
int coinChange(int money) {
	const int MAX = money + 1;
	vector<int> dp(money + 1, MAX);
	dp[0] = 0;

	for (int i = 1; i <= money; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= mon[j]) {
				dp[i] = min(dp[i], dp[i - mon[j]] + 1);
			}
		}
	}

	return dp[money] == MAX ? -1 : dp[money];
}


int main()
{
	cin >> money;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> mon[i];
	}

	//cout <<f2(money, 0);
	//cout << min_Cnt;
	f(money, 0);
	cout << "1: " << min_Cnt << "\n";
	cout << "2: " << f2(money) << "\n";
	cout << "3: " << coinChange(money) << "\n";

	return 0;
}