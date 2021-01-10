#include <iostream>

using namespace std;

int N;

int f(int n)
{
	// n=1: 1									=> 1
	// n=2: 1+1, 2								=> 2
	// n=3: 1+1+1, 2+1, 1+2						=> 3
	// n=4: 1+1+1+1, 2+1+1, 1+2+1 / 1+1+2,  2+2 => 5 (n=3) + (n+2)
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 3;
	else if (n >= 4) return f(n - 1) + f(n - 2);
}

int main()
{
	cin >> N;

	cout << f(N);
}