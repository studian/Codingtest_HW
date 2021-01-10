


#include <iostream>

using namespace std;

int N, M;

int f(int n)
{
	// n=1: 1ea
	// n=2: 1+1, 2 => 2ea
	// n=3: 1+1+1, 2+1, 3 => 3ea
	// n=4: 1+1+1+1, 2+1+1, 3+1,/ 2+2, 4 => 5ea
	// n=5: 1+1+1+1+1, 2+1+1+1, 3+1+1, / 2+2+1, 4+1, / 3+2, 5 => 7ea
	//cout << n << " " << M << "\n";

	//if (n > M) return 0;

	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 3;
	else if (n > 3) return f(n - 1) + 2;

}
int main()
{
	cin >> N >> M;

	cout << f(N);
}