#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int sieve[N];
int main()
{
	int i, j;
	for (i = 2; i < N; i++)
		sieve[i] = 1;
	for (i = 2; i * i < N; i++)
	{
		if (sieve[i] == 1)
		{
			for (j = 2; i * j < N; j++)
				sieve[i * j] = 0;
		}
	}
	for (i = 0; i < N - 1; i++)
		sieve[i + 1] += sieve[i];
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		cout << sieve[n] << "\n";
	}
	return 0;
}