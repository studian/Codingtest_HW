#include <iostream>

using namespace std;

int N;

int f(int n)
{
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n >= 3) return f(n - 1) + f(n - 2);
}

int main()
{
	cin >> N;

	cout << f(N);
}