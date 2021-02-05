#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll fact[100005];
ll invfact[100005];

ll power(ll a, ll n)
{
    if (n == 0) return 1;
    ll ans = 1;
    ll val = a;
    while (n)
    {
        if (n % 2)
        {
            ans *= val;
            ans %= M;
        }
        val *= val;
        val %= M;
        n /= 2;
    }
    return ans;
}

void pre()
{
    fact[0] = fact[1] = 1;
    invfact[0] = invfact[1] = 1;
    for (int i = 2; i <= 100000; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= M;
        invfact[i] = invfact[i - 1] * power(i, M - 2);
        invfact[i] %= M;
    }
}
ll ncr(ll n, ll r)
{
    if (n < r || n < 0 || r < 0) return 0;
    ll ty = fact[n];
    ty *= invfact[n - r];
    ty %= M;
    ty *= invfact[r];
    ty %= M;
    return ty;
}
ll solve(ll x, ll sum)
{
    ll count = 0;
    for (int i = 0; i <= x; i++)
    {
        ll val = ncr(x, i) * ncr(sum + x - 1, x - 1);
        val %= M;
        sum -= 10;
        if (i % 2 == 0)
        {
            count += val;
            count %= M;
        }
        else
        {
            count -= val;
            count += M;
            count %= M;
        }
    }
    return count;
}
int main() {
    pre();
    int t;
    cin >> t;
    while (t--)
    {
        ll s;
        cin >> s;
        ll temp = s;
        int count = 0;
        while (temp)
        {
            count++;
            temp /= 10;
        }
        ll val = 1;
        ll answer = 0;
        for (int i = 1; i <= count; i++)
        {
            if (s % val == 0)
            {
                ll sum = s / val;
                if (sum >= 0 && sum <= 9 * i)
                {
                    answer += solve(i, sum);
                    //     cout<<answer<<" "<<i<<" "<<sum<<endl;
                    answer %= M;
                }
            }
            val *= 10;
            val++;
        }
        cout << answer << endl;
    }
}