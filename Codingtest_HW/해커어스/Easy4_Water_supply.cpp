#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

// N: 1<=N<=200000
vector<int>adjacent[200001];
int visited[200001];
int blocked[200001];
int sz;

void dfs(int u)
{
    visited[u] = 1;//true;
    sz++;
    for (int i = 0; i < adjacent[u].size(); i++)
    {
        int v = adjacent[u][i];
        if (visited[i] == 0 && blocked[v] == 0)
        {
            dfs(v);
        }
        // �� �־��?: �ڿ� ��尡 block�� ��忩��, 
        // block�� ��� �����ؼ� �������Ƿ� 1+�ؾ���
        else if (blocked[v] == 1)
        {
            sz++;
        }
    }
}

int main()
{
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

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0 && blocked[i] == 0)
        {
            sz = 0;
            dfs(i);
            ans = max(ans, sz);
        }
    }
    cout << ans << endl;
    return 0;
}