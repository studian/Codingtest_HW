#include <iostream>

using namespace std;

int n, r;

int f(int p, int q)
{
	if (q == 1) return p;
	if (p == q) return 1;
	if (p < q) return 0;

	return f(p - 1, q - 1) + f(p - 1, q);
}
int main()
{
	cin >> n >> r;

	cout << f(n, r);
}