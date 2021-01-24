#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
	int q;
	ll n;
	cin >> q;
	while (q--)
	{
		cin >> n;
		cout << (ll)n * (n - 1) + 1 << "\n";
	}

}