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

			if (a[idx - 1] == x) // ���� ���� �ߺ�üũ�ϴ� �� x�� �ִµ�
			{
				if (x != value) // �ߺ�üũ�ϴ� �� x�� value�� �����ϴ� ���
				{
					a[idx - 1] = value;
					for (int i = idx - 1; i < n; i++)
					{
						c[i] = c[i]-1;
					}
				}
				else{ // �翬�� �������� ���ŵǴ� ���� ������ �ƹ��͵� ����
				}
			}
			else // ���� �ش� ���� x�ʹ� �ٸ����� �ִµ�
			{
				if (x == value) // �ߺ�üũ�ϴ� �� x�� �����ϴ� ���
				{
					a[idx - 1] = value;
					for (int i = idx - 1; i < n; i++)
					{
						c[i] = c[i] + 1;
					}
				}
				else { // �翬�� �������� ���ŵǴ� ���� ������ �ƹ��͵� ����
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