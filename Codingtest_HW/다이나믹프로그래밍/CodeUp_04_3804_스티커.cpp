#include<iostream>
#include<algorithm>

using namespace std;

int N;
int a[3][100001]; // [줄번호][칸번호]
int dp[3][100001];


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Tc;
    cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        cin >> N;
        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> a[i][j];
            }
        }

        dp[1][0] = dp[2][0] = 0;
        dp[1][1] = a[1][1]; // 왜?
        dp[2][1] = a[2][1]; // 왜?

        for (int i = 2; i <= N; i++)
        {
            dp[1][i] = a[1][i] + max(dp[2][i - 1], dp[2][i - 2]);
            dp[2][i] = a[2][i] + max(dp[1][i - 1], dp[1][i - 2]);
        }

        /*for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }*/
        cout << max(dp[1][N], dp[2][N]) << endl;
    }

    return 0;
}

//1. 질문: 
//dp[1][1] = a[1][1]; // 왜?
//dp[2][1] = a[2][1]; // 왜?
//
//2. 양쪽 방향 모두 고려해야하는것은 아닌지? 왜 한쪽 방향만 고려하는지?
//예를들어
//dp[1][i] = a[1][i] + max(dp[2][i - 1], dp[2][i - 2]); 
//가 아니라
//
//int a1 = max(dp[2][i - 1], dp[2][i - 2]);
//int a2 = max(dp[2][i + 1], dp[2][i + 2]);
//dp[1][i] = a[1][i] + max(a1, a2);
//가 되야 하는 것은 아닌지?
