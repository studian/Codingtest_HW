#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

int B/*예산*/, N/*개수*/, cost[22], max_cost;

// ith_activity번활동, ith_activity-1까지의 합계
void f(int ith_activity, int sum)  
{
	printf("f(%d,%d )\n", ith_activity, sum);
	// 일부 케이스에서 틀림
	if (ith_activity > N+1 || sum > B) return;
	if (max_cost < sum)
	{
	
		max_cost = max(max_cost, sum);
		printf("MaxCost갱신 %d \n", max_cost);
		//return;
	}
	
	//if (ith_activity == N + 1)
	//{
	//	if (sum <= B && sum > max_cost) //예산 보다는 작고 현재 값보다는 크면.
	//		max_cost = sum;

	//	return;
	//}
	f(ith_activity + 1, sum + cost[ith_activity]); // ith_activity번째 활동을 포함하거나
	f(ith_activity + 1, sum);         // 포함하지 않 거나
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