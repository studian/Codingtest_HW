#include<iostream>
#include<algorithm>

using namespace std;

// dp[n] = a[n] + max(dp[n-2], a[n-1]+dp[n-3]), n>=4
int N;
int a[301];
int dp[301];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}

	dp[1] = a[1];
	dp[2] = max(dp[1]+ a[2], a[2]);
	dp[3] = a[3] + max(dp[1], a[2]);

	for (int i = 4; i <= N; i++)
	{
		dp[i] = a[i] + max(dp[i - 2], a[i - 1] + dp[i - 3]);
	}

	/*for (int i = 1; i <= N; i++)
	{
		cout << a[i] << " " << dp[i] << "\n";
	}*/

	cout << dp[N];
}
