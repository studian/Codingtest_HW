#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N; // ���ǰ���, 1 <= N <= 100
int W; // �賶�� ����, 1 <= W <= 10000

int w[101]; // ���� ����
int v[101]; // ���� ����
int dp[101][10001]; //[���ǰ���][�賶����]
//  dp[i][j] = ������ i��° ���� ������ ���� �� 
//		       ���� j�� �ʰ����� �����鼭 
//			   ���� �� �ִ� ������ ������ �ִ밪

int jegui(int idx, int pre_w)
{
	if (idx == N + 1) return 0;

	int n1 = 0;
	if(pre_w + w[idx] <= W)
		n1 = v[idx] + jegui(idx + 1, pre_w + w[idx]);	// ����(w[idx])�� ���ԵǴ� ���

	int n2 = 0 + jegui(idx + 1, pre_w + 0);				// ����(w[idx])�� ���Ե��� �ʴ� ���

	return max(n1, n2);
}

int DynamicProgramming(int idx, int pre_w)
{
	if (dp[idx][pre_w] > 0) return dp[idx][pre_w]; // �߰�

	if (idx == N + 1) return 0;

	int n1 = 0;
	if (pre_w + w[idx] <= W)
		n1 = v[idx] + DynamicProgramming(idx + 1, pre_w + w[idx]);	// ����(w[idx])�� ���ԵǴ� ���

	int n2 = 0 + DynamicProgramming(idx + 1, pre_w + 0);				// ����(w[idx])�� ���Ե��� �ʴ� ���

	return dp[idx][pre_w] = max(n1, n2); // ����
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

// ��ǰ