#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

int B/*����*/, N/*����*/, cost[22], max_cost;

// ith_activity��Ȱ��, ith_activity-1������ �հ�
void f(int ith_activity, int sum)  
{
	printf("f(%d,%d )\n", ith_activity, sum);
	// �Ϻ� ���̽����� Ʋ��
	if (ith_activity > N+1 || sum > B) return;
	if (max_cost < sum)
	{
	
		max_cost = max(max_cost, sum);
		printf("MaxCost���� %d \n", max_cost);
		//return;
	}
	
	//if (ith_activity == N + 1)
	//{
	//	if (sum <= B && sum > max_cost) //���� ���ٴ� �۰� ���� �����ٴ� ũ��.
	//		max_cost = sum;

	//	return;
	//}
	f(ith_activity + 1, sum + cost[ith_activity]); // ith_activity��° Ȱ���� �����ϰų�
	f(ith_activity + 1, sum);         // �������� �� �ų�
}

int main() 
{
	int i;
	cin >> B >> N;

	for (i = 1; i <= N; i++)
		cin >> cost[i];

	f(1, 0);
	cout << max_cost;

	return 0;
}