#include<iostream>
#include<assert.h>
#include<algorithm>

using namespace std;

int N;
int arr[12][12];
int max_sum = 0;
int v[12] = { 0, };	//��θ� �����ϴ� �迭

//�������� ��(row), �������� ��(column, ���)�̶�� �θ���

//�ʿ��� Ž���ΰ�? 
//bool isVisited(int row, int h) {
//	v[h] = 
//	for (int i = 1; i <= row; i++) 
//	{
//		if (v[i] == h) 
//			return false;
//	}
//	return true;
//}


//��Ʈ��ŷ ����Ž��
void f(int row, int sum) {
	printf("f(%d, %d) \n", row, sum);
	if (row == N + 1) {

		if (sum > max_sum) {
			max_sum = sum;
			printf("Max SUm ���� %d \n", max_sum);
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