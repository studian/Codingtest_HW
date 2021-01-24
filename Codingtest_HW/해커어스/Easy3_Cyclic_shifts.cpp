#include <iostream>

using namespace std;

// 1<= N <= 66535: (2^16)-1 = 66535, 16 bit : unsigned short in

int main()
{
	int t;
	unsigned short int n, m;
	cin >> t;
	while (t--)
	{
		char c;
		cin >> n >> m >> c;

		if (c == 'L')
		{
			unsigned short int left = (n << m);
			unsigned short int right = (n >> (16-m));
			cout << (left | right) << "\n";
		}			
		else if (c == 'R')
		{
			unsigned short int right = (n >> m);
			unsigned short int left = (n << (16 - m));
			cout << (left | right) << "\n";
		}
	}
	return 0;
}