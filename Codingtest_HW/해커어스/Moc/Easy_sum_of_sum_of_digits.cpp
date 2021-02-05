/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code her

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll SumOfDigits(ll x)
{
    ll sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;

        if (sum > 9)
        {
            x += sum;
            sum = 0;
        }
    }
    return sum;
}


bool compare(ll x, ll y)
{
    return SumOfDigits(x) < SumOfDigits(y);
}

ll a[100001];
ll l[100001];
ll r[100001];

int main()
{
    ll n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, compare);

    l[0] = SumOfDigits(a[0]);

    for (int i = 1; i < n; i++)
    {
        l[i] = l[i - 1] + SumOfDigits(a[i]);
    }

    r[n - 1] = SumOfDigits(a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = r[i + 1] + SumOfDigits(a[i]);
    }

    while (q--)
    {
        int x, k;
        cin >> x >> k;

        if (x == 2)
        {
            cout << l[k - 1] << "\n";
        }
        else
        {
            cout << r[n - k] << "\n";
        }
    }

}
