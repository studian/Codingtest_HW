#include<iostream>
#include<algorithm>

using namespace std;

int dp[101][100001]; //[구간][지난시간] 
//dp[i][j]: 구간i를 j분 안에 지났을때 최대로 얻을수 잇는 금액

int main()
{
	int N, K, walking_time, walking_money, cycle_time, cycle_money;
	cin >> N >> K; // K는 최대 여행 시간

	for (int i = 1; i <= N; i++)
	{
		cin >> walking_time >> walking_money >> cycle_time >> cycle_money; // 도보시간, 도보모금액, 자전거시간, 자전거모금액

		if (i == 1)
		{
			dp[i][walking_time] = walking_money;
			dp[i][cycle_time] = cycle_money;
		}
		else
		{
			for (int j = 0; j <= K; j++)
			{
				if (dp[i - 1][j] == 0) continue; // 이전도시 안갔음
				else
				{
					if (j + walking_time <= K) // 도보로 가는 경우
						dp[i][j + walking_time] = max(dp[i][j + walking_time], dp[i-1][j] + walking_money);

					if (j + cycle_time <= K) // 자전거로 가는 경우
						dp[i][j + cycle_time] = max(dp[i][j + cycle_time], dp[i - 1][j] + cycle_money);
				}
			}
		}
	}

	int m = -1;
	for (int i = 1; i <= K; i++)
	{
		m = max(m, dp[N][i]);
	}
	cout << m;
	return 0;
}