#include <iostream>
#include <algorithm>
using namespace std;

// 1<=n<=1000 000
int a[1000001];
int c[1000001];

int main()
{
	int n, x;
	cin >> n >> x;

	int cc = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		if (a[i] == x) cc++;
		c[i] = cc;
	}

	/*cout << "@\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i < n; i++)
	{
		cout << c[i] << " ";
	}
	cout << "\n";*/

	int ai = 0;
	cin >> ai;
	for (int j = 0; j < ai; j++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int l, r, k;
			cin >> l >> r >> k;

			int ans = -1;
			if (c[l-1] == c[r - 1])
			{
				if (a[l - 1] == x)
				{
					cout << l << "\n";
				}
				else
				{
					cout << -1 << "\n";
				}
			}
			else // c[l] < c[r]
			{
				int arr_idx = lower_bound(c, c + r + 1, k + c[l - 1]) - c;

				if (a[l - 1] == x)
				{
					cout << arr_idx << "\n";
				}
				else
				{
					cout << arr_idx + 1 << "\n";
				}
				
			}
		}
		else if (type == 2)
		{
			int idx, value;
			cin >> idx >> value;

			if (a[idx - 1] == x) // 원래 값에 중복체크하는 값 x가 있는데
			{
				if (x != value) // 중복체크하는 값 x를 value로 변경하는 경우
				{
					a[idx - 1] = value;
					for (int i = idx - 1; i < n; i++)
					{
						c[i] = c[i]-1;
					}
				}
				else{ // 당연히 원래값과 갱신되는 값이 같으면 아무것도 안함
				}
			}
			else // 원래 해당 값에 x와는 다른값이 있는데
			{
				if (x == value) // 중복체크하는 값 x로 변경하는 경우
				{
					a[idx - 1] = value;
					for (int i = idx - 1; i < n; i++)
					{
						c[i] = c[i] + 1;
					}
				}
				else { // 당연히 원래값과 갱신되는 값이 같으면 아무것도 안함
					a[idx - 1] = value;
				}
			}
			

			/*cout << "@\n";
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << " ";
			}
			cout << "\n";

			for (int i = 0; i < n; i++)
			{
				cout << c[i] << " ";
			}
			cout << "\n";*/
		}
	}

	return 0;
}