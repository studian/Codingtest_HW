#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int search(vector<int>& grp, int cap)
{
	int low = 0, high = grp.size() - 1, prev = -1;
	while (low <= high)
	{
		//int mid = low + (high - low) / 2;
		int mid = (low + high) / 2;
		if (grp[mid] < cap)
		{
			prev = mid;
			low = mid + 1;
		}
		else if (grp[mid] > cap)
		{
			high = mid - 1;
		}
		else
			return mid;
	}
	return prev;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int N, M;
	

	cin >> N >> M;
	//int A[100001];
	vector<int> A(N);
	vector<int> B(M);
	//int B[M];

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> B[i];
	}

	//sort(A, A + N);
	//sort(B, B + M);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	// ���� �׷�(A[i])�̸� ���� �̵��ؾ� ������,
	// �ο����� ���� ���� �׷��� �� �ο��� > ���� ���� ������ �� �ִ� ������� �ִ� �����ο����� ũ��
	// ���� �̵��� �Ұ����ϹǷ�, -1�� ����ؾ� ��
	if (A[N - 1] > B[M - 1]) { 
		cout << "-1" << "\n";
	}
	else
	{
		int cnt = 0;
		while (A.size() > 0)
		{
			for (int i = M - 1; i >= 0 && A.size() > 0; i--) {
				int index = search(A, B[i]);
				//cout << "B["<<i<<"]: " << B[i] << " A[" << index << "]: " << A[index] << "\n";
				if (index != -1)
				{
					//cout << "erase: A[" << index << "]: " << A[index] << "\n";
					A.erase(A.begin() + index);
				}
				else
				{
					//cout << "break loof\n";
					break;
				}
			}
			//cout << "count\n";
			cnt += 2;
		}
		cnt -= 1;
		cout << cnt << "\n";
	}

}