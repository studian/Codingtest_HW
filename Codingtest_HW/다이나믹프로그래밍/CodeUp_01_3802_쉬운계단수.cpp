#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;



#define mod 1000000000

int main(void) 
{
	int N;
	int dp[101][10] = {}; // [자리수][숫자]
	cin >> N;

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1; // 자리수 길이가 1
	}
		
	for (int i = 2; i <= N; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			if (j == 0) //숫자0은 이전단계[i-1] 숫자1에서만 와짐
			{
				dp[i][0] = dp[i - 1][1] % mod;
			}				
			else if (j == 9) //숫자9은 이전단계[i-1] 숫자8에서만 와짐
			{
				dp[i][9] = dp[i - 1][8] % mod;
			}				
			else //숫자0과 9를 제외한 나머지 숫자들은 이전단계[i-1]에서 해당숫자+/-1 에서 와짐
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
