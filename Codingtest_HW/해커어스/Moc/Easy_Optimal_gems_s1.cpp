#include <bits/stdc++.h>
using namespace std;
#define MAX 21
#define mod 1000000007
int dp[MAX][MAX][MAX][MAX][4];
int solve(int a, int b, int c, int d, int prev)
{
	if (dp[a][b][c][d][prev] != -1)
		return dp[a][b][c][d][prev];
	else if (a == 0 && b == 0 && c == 0 && d == 0)
	{
		dp[a][b][c][d][prev] = 1;
		return dp[a][b][c][d][prev];
	}
	long long ans = 0;
	if (prev == 0)
	{
		if (b != 0)
			ans = (ans + solve(a, b - 1, c, d, 1)) % mod;
		if (c != 0)
			ans = (ans + solve(a, b, c - 1, d, 2)) % mod;
		if (d != 0)
			ans = (ans + solve(a, b, c, d - 1, 3)) % mod;
	}
	else if (prev == 1)
	{
		if (a != 0)
			ans = (ans + solve(a - 1, b, c, d, 0)) % mod;
		if (c != 0)
			ans = (ans + solve(a, b, c - 1, d, 2)) % mod;
		if (d != 0)
			ans = (ans + solve(a, b, c, d - 1, 3)) % mod;
	}
	else if (prev == 2)
	{
		if (a != 0)
			ans = (ans + solve(a - 1, b, c, d, 0)) % mod;
		if (b != 0)
			ans = (ans + solve(a, b - 1, c, d, 1)) % mod;
		if (d != 0)
			ans = (ans + solve(a, b, c, d - 1, 3)) % mod;
	}
	else
	{
		if (a != 0)
			ans = (ans + solve(a - 1, b, c, d, 0)) % mod;
		if (b != 0)
			ans = (ans + solve(a, b - 1, c, d, 1)) % mod;
		if (c != 0)
			ans = (ans + solve(a, b, c - 1, d, 2)) % mod;
	}
	dp[a][b][c][d][prev] = ans;
	return ans;
}
void util(int a, int b, int c, int d)
{
	memset(dp, -1, sizeof(dp));
	long long ans = 0;
	if (a != 0)
		ans = (ans + solve(a - 1, b, c, d, 0)) % mod;
	if (b != 0)
		ans = (ans + solve(a, b - 1, c, d, 1)) % mod;
	if (c != 0)
		ans = (ans + solve(a, b, c - 1, d, 2)) % mod;
	if (d != 0)
		ans = (ans + solve(a, b, c, d - 1, 3)) % mod;
	cout << ans;
}
int main()
{
	int n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;
	util(n1, n2, n3, n4);
	return 0;
}