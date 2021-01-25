#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

typedef long long ll;

using namespace std;

// N: 1<=N<=200000
vector<int>adjacent[200001];
int visited[200001];
int blocked[200001];
int sz = 0;
int ans = 1;
void dfs(int u)
{
    sz++;
    visited[u] = 1;//true;
    for (int i = 0; i < adjacent[u].size(); i++)
    {
        int v = adjacent[u][i];
        if (visited[v] == 0 && blocked[v] == 0)
        {
            dfs(v);
        }
        else if (blocked[v] == 1) {
            //visited[v] = 1;
            sz++;
            //visited[v] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> blocked[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sz = 0;
        if (visited[i] == 0 && blocked[i] == 0)
        {
            dfs(i);
        }
        if (ans < sz) {
            ans = sz;
        }
    }
    cout << ans << endl;
    return 0;
}