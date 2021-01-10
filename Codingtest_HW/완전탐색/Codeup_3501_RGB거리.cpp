#include<iostream>
#include<assert.h>
#include<algorithm>

using namespace std;

int N;
int rgb[16][3];
int min_ans = 0x7fffffff;

void f(int idx, int rgb_idx, int crt_total)
{
	crt_total += rgb[idx][rgb_idx];

	if (idx > N) return;
	if (idx == N)
	{
		min_ans = min(min_ans, crt_total);
		return;
	}
	
	for (int i = 0; i < 3; i++) 
	{
		if (i != rgb_idx)
		{
			f(idx + 1, i, crt_total);
		}		
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}

	for (int i = 0; i < 3; i++)
	{
		f(0, i, 0);
	}

	cout << min_ans;


	return 0;
}