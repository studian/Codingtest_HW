#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

int B/*����*/, N/*����*/, cost[22], max_cost;

// ith_activity��Ȱ��, ith_activity-1������ �հ�
void f(int ith_activity, int sum)  
{
	//printf("f(%d,%d )\n", ith_activity, sum);
	if (ith_activity > N+1 || sum > B) return;
	if (max_cost < sum)
	{
	
		max_cost = max(max_cost, sum);
		printf("MaxCost���� %d \n", max_cost);
	}
	
	f(ith_activity + 1, sum + cost[ith_activity]); // ith_activity��° Ȱ���� �����ϰų�
	f(ith_activity + 1, sum);         // �������� �� �ų�
}

// f2: ���, ���ϰ� �ְ�..�𸣰ڴ�..
int f2(int num)
{
	if (num < 0) return 0;
	if (num > B) return 0;
	for (int i = 1; i <= n; i++)
	{
		if (num == cost[i]) return 1;
	}

	int sub_min = 0x3fffffff;
	for (int i = 1; i <= N; i++)
	{
		//sub_min = min(sub_min, f2(num + mon[i]));
	}

	return sub_min + 1;
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