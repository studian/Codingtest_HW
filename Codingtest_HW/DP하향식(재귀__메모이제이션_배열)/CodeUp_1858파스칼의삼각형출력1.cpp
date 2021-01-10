#include <iostream>

using namespace std;

int N, K;

int f(int n, int k)
{
	if (n == 1 && k == 1) return 1;
	if (n < 1) return 0;
	if (k < 1 || k > n) return 0;

	return f(n-1, k-1)+ f(n - 1, k);
}
int main()
{
	cin >> N >> K;

	cout << f(N, K);
}