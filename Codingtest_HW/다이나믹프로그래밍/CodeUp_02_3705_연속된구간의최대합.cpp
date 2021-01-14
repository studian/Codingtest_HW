#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int sum_arr[100001];
int dp[100001][100001];


int main()
{
	cin >> n;

	sum_arr[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		sum_arr[i] = sum_arr[i - 1] + arr[i];
	}

	int max_sum = -999999999;

	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = i; j <=n ; j++)
		{
			//sum += arr[j];
			sum = sum_arr[j] - sum_arr[i - 1];
			dp[i][j] = sum;
			max_sum = (max_sum < sum) ? sum : max_sum;
		}
		
		//cout << sum << " " << max_sum << "\n";
	}


	cout << max_sum;
}