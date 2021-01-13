
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<algorithm>
#include <stdio.h>

using namespace std;

int N, S;
int num[21] = { 0, };

int f(int idx, int crt_sum)
{
	printf("f(%d, %d)\n", idx, crt_sum);

	if (idx > 0 && crt_sum == S)
	{
		return 0;
	}
	else {//if (crt_sum < 0) {
		return 22;
	}

	int sumCnt = 21;

	for (int i = 0; i <= N; i++)
	{
		if (crt_sum - num[i] >= 0){
			sumCnt = min(sumCnt, f(idx - 1, crt_sum + num[i]) + 1);
			break;
		}
		
	}

	printf("f(%d, %d, %d)\n", idx, crt_sum, sumCnt);
	return sumCnt;
}


int main()
{
	cin >> N >> S;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	cout << f(N, 0);





}