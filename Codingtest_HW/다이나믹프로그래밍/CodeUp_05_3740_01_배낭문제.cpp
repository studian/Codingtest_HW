#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N; // 물건개수, 1 <= N <= 100
int W; // 배낭의 무게, 1 <= W <= 10000

int w[101]; // 물건 무게
int v[101]; // 물건 가격
int dp[101][10001]; //[물건개수][배낭무게]
//  dp[i][j] = 물건을 i번째 까지 가방을 넣을 때 
//		       무게 j를 초과하지 않으면서 
//			   담을 수 있는 가격의 총합의 최대값

int jegui(int idx, int pre_w)
{
	if (idx == N + 1) return 0;

	int n1 = 0;
	if(pre_w + w[idx] <= W)
		n1 = v[idx] + jegui(idx + 1, pre_w + w[idx]);	// 현재(w[idx])가 포함되는 경우

	int n2 = 0 + jegui(idx + 1, pre_w + 0);				// 현재(w[idx])가 포함되지 않는 경우

	return max(n1, n2);
}

int DynamicProgramming(int idx, int pre_w)
{
	if (dp[idx][pre_w] > 0) return dp[idx][pre_w]; // 추가

	if (idx == N + 1) return 0;

	int n1 = 0;
	if (pre_w + w[idx] <= W)
		n1 = v[idx] + DynamicProgramming(idx + 1, pre_w + w[idx]);	// 현재(w[idx])가 포함되는 경우

	int n2 = 0 + DynamicProgramming(idx + 1, pre_w + 0);				// 현재(w[idx])가 포함되지 않는 경우

	return dp[idx][pre_w] = max(n1, n2); // 수정
}

int main()
{
	cin >> N >> W;
	for (int i = 1; i <= N; i++)
		cin >> w[i] >> v[i];

	//cout << jegui(1, 0) << "\n";
	cout << DynamicProgramming(1, 0) << "\n";

	return 0;
}

// 못품