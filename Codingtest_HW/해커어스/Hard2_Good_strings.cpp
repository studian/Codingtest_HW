// In the name of Allah.
// We're nothing and you're everything.
// add stdc++.h in "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29333\include\bits"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 14, maxv = 5e4 + 14;
int n, dp[maxn], dval[maxn], hval[maxn], fin[maxn];
string s;
bool dfs(int v) {
    // cerr << v << endl;
    bitset<maxv> knapsack;
    knapsack[0] = true;
    int sum = 0;
    auto add = [&knapsack, &sum](int x) {
        sum += x;
        return knapsack << x;
    };
    for (int i = v + 1; i < fin[v] - 1; )
        if (s[i] == '#')
            knapsack |= add(hval[i++]);
        else {
            if (!dfs(i))
                return false;
            knapsack = add(dp[i]) | add(dval[i]);
            i = fin[i];
        }
    if (v == 0)
        return true;
    int near = dval[v];
    while (near >= 0 && !knapsack[near])
        near--;
    // cerr << v << " = " << near << '\n';
    if (near == -1)
        return false;
    dp[v] = sum - near;
    return true;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s;
    for (auto c : s)
        if (c == '#') {
            int i;
            cin >> i;
            cin >> hval[i];
        }
    for (auto c : s)
        if (c == '(') {
            int b;
            cin >> b;
            cin >> fin[b] >> dval[b];
            fin[b]++;
        }
    s = '(' + s + ')';
    fin[0] = s.size();
    cout << (dfs(0) ? "Yes" : "No") << '\n';
}