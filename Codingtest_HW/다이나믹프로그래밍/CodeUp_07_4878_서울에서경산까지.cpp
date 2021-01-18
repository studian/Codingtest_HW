#include<iostream>
#include<algorithm>

using namespace std;

int dp[101][100001]; //[����][�����ð�] 
//dp[i][j]: ����i�� j�� �ȿ� �������� �ִ�� ������ �մ� �ݾ�

int main()
{
	int N, K, walking_time, walking_money, cycle_time, cycle_money;
	cin >> N >> K; // K�� �ִ� ���� �ð�

	for (int i = 1; i <= N; i++)
	{
		cin >> walking_time >> walking_money >> cycle_time >> cycle_money; // �����ð�, ������ݾ�, �����Žð�, �����Ÿ�ݾ�

		if (i == 1)
		{
			dp[i][walking_time] = walking_money;
			dp[i][cycle_time] = cycle_money;
		}
		else
		{
			for (int j = 0; j <= K; j++)
			{
				if (dp[i - 1][j] == 0) continue; // �������� �Ȱ���
				else
				{
					if (j + walking_time <= K) // ������ ���� ���
						dp[i][j + walking_time] = max(dp[i][j + walking_time], dp[i-1][j] + walking_money);

					if (j + cycle_time <= K) // �����ŷ� ���� ���
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