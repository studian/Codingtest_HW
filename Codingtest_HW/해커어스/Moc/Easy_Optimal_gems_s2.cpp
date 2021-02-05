/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
//#include "bits/stdc++.h"
#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

//#define int long long

const ll mod = 1e9 + 7;

ll dp[5][22][22][22][22];

ll go(ll n0, ll n1, ll n2, ll n3, ll prev)
{
    if (n0 == 0 && n1 == 0 && n2 == 0 && n3 == 0) return 1;

    ll& ans = dp[prev][n0][n1][n2][n3];
    if (~ans) return ans;

    ans = 0;

    if (prev != 0 && n0 > 0)
    {
        ans = (ans + go(n0 - 1, n1, n2, n3, 0)) % mod;
    }

    if (prev != 1 && n1 > 0)
    {
        ans = (ans + go(n0, n1 - 1, n2, n3, 1)) % mod;
    }

    if (prev != 2 && n2 > 0)
    {
        ans = (ans + go(n0, n1, n2 - 1, n3, 2)) % mod;
    }

    if (prev != 3 && n3 > 0)
    {
        ans = (ans + go(n0, n1, n2, n3 - 1, 3)) % mod;
    }
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    ll n0, n1, n2, n3;
    cin >> n0 >> n1 >> n2 >> n3;
    cout << go(n0, n1, n2, n3, 4);

    return 0;
}