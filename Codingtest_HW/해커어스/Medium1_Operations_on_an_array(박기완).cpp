#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1<=n<=1000 000
int a[1000001];

int main()
{
	int n, x;
	cin >> n >> x;
	
	vector<int> data;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];

		if (a[i] == x) {

		}
	}

	int ai = 0;
	cin >> ai;
	for (int j = 1; j <= ai; j++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int l, r, k;
			cin >> l >> r >> k;

			int ans = -1;
			int cnt = 0;
			for (int i = l; i <= r; i++)
			{
				if (a[i] == x)
				{
					cnt++;
					if (cnt == k)
					{
						ans = i;
						break;
					}
				}
			}

			cout << ans << "\n";
		}
		else if (type == 2)
		{
			int idx, value;
			cin >> idx >> value;
			a[idx] = value;
		}
	}

	return 0;
}