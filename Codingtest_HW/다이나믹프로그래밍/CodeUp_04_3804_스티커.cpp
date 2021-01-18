#include<iostream>
#include<algorithm>

using namespace std;

int N;
int a[3][100001]; // [�ٹ�ȣ][ĭ��ȣ]
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
        dp[1][1] = a[1][1]; // ��?
        dp[2][1] = a[2][1]; // ��?

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

//1. ����: 
//dp[1][1] = a[1][1]; // ��?
//dp[2][1] = a[2][1]; // ��?
//
//2. ���� ���� ��� ����ؾ��ϴ°��� �ƴ���? �� ���� ���⸸ ����ϴ���?
//�������
//dp[1][i] = a[1][i] + max(dp[2][i - 1], dp[2][i - 2]); 
//�� �ƴ϶�
//
//int a1 = max(dp[2][i - 1], dp[2][i - 2]);
//int a2 = max(dp[2][i + 1], dp[2][i + 2]);
//dp[1][i] = a[1][i] + max(a1, a2);
//�� �Ǿ� �ϴ� ���� �ƴ���?
