#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;



#define mod 1000000000

int main(void) 
{
	int N;
	int dp[101][10] = {}; // [�ڸ���][����]
	cin >> N;

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1; // �ڸ��� ���̰� 1
	}
		
	for (int i = 2; i <= N; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			if (j == 0) //����0�� �����ܰ�[i-1] ����1������ ����
			{
				dp[i][0] = dp[i - 1][1] % mod;
			}				
			else if (j == 9) //����9�� �����ܰ�[i-1] ����8������ ����
			{
				dp[i][9] = dp[i - 1][8] % mod;
			}				
			else //����0�� 9�� ������ ������ ���ڵ��� �����ܰ�[i-1]���� �ش����+/-1 ���� ����
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
			}				
		}
	}

	int sum = 0;
	for (int i = 1; i < 10; i++)
		sum = (sum + dp[N][i]) % mod;
	cout << sum;
	//printf("%d\n", sum % mod);
}
