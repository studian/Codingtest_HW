//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cassert>
//typedef long long int ll
//#define ll 

typedef long long int ll;

using namespace std;

#define MAX 200005

vector<int>adjacent[MAX];
int dp[MAX];
int visited[MAX];

void dfs(int u)
{
    visited[u] = 1;
    dp[u] = 1;
    for (int i = 0; i < adjacent[u].size(); i++)
    {
        int v = adjacent[u][i];
        if (!visited[v])
        {
            dfs(v);
        }
        dp[u] = max(dp[u], 1 + dp[v]);
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    assert(N <= 200000 && M <= 1000000);
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        adjacent[u].push_back(v);
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    int ans = -1;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}
