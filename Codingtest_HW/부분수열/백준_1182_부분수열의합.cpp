#include <iostream>
#include<algorithm>

using namespace std;

int N, S;
int number[21];

int f(int n)
{
	if (n <0) return 0;

	for (int i = 1; i <= N; i++)
	{
		if (number[i] == n)
			return 1;
	}

	int min_num = 0x3fffffff;

	for (int i = 1; i <= N; i++)
	{
		min_num = min(min_num, f(n - number[i]) + 1);
	}
	return min_num;
}

int main()
{
	cin >> N >> S;

	for (int i = 1; i <= N; i++)
	{
		cin >> number[i];
	}

	//cout << f(S);

	sort(number + 1, number + 1 + N);

	if (number[0] < 0)
	{
		S += number[0];

		for (int i = 1; i <= N; i++)
		{
			number[i] += number[0];
		}
	}

	cout << f(S);
}