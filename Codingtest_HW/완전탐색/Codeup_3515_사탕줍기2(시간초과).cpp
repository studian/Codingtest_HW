#include<iostream>
#include<assert.h>
#include<algorithm>

using namespace std;

int N;
int arr[12][12];
int max_sum = 0;
int v[12] = { 0, };	//경로를 저장하는 배열

//가로줄을 행(row), 세로줄을 열(column, 기둥)이라고 부른다

//필요한 탐색인가? 
//bool isVisited(int row, int h) {
//	v[h] = 
//	for (int i = 1; i <= row; i++) 
//	{
//		if (v[i] == h) 
//			return false;
//	}
//	return true;
//}


//백트래킹 완전탐색
void f(int row, int sum) {
	printf("f(%d, %d) \n", row, sum);
	if (row == N + 1) {

		if (sum > max_sum) {
			max_sum = sum;
			printf("Max SUm 갱신 %d \n", max_sum);
		}

		return;
	}


	for (int h = 1; h <= N; h++) {
		if(v[h] == 0){
			v[h] = 1;
			f(row + 1, sum + arr[row][h]);
			v[h] = 0;
			
		}
	}
}


int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	f(1, 0);
	cout << max_sum;

	return 0;
}