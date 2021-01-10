#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int a, b;

int min_cnt = 0x7fffffff;

void f(int t, int cnt)
{
	if (t == 0)
	{
		if (min_cnt > cnt)
		{
			min_cnt = cnt;
		}
		return;
	}
	
	if (t < 0)
	{
		t = -1 * t;
	}

	// 조건문 없이 푸는것은 모르겠음
	if (t > 7)
	{
		f(t - 10, cnt + 1);
	}
	else if (t > 3)
	{
		f(t - 5, cnt + 1);
	}
	else
	{
		f(t - 1, cnt + 1);
	}	
}

int main()
{
	cin >> a >> b;

	int abs_num = abs(b - a);

	f(abs_num, 0);

	cout << min_cnt;

	return 0;
}