// Write your code here
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int LIS(vector<int>& v)
{
    if (v.size() == 0) return 0;

    vector<int> lis(v.size(), 0); // ������ v�迭 ũ�� ��ŭ �����, 0���� �ʱ�ȭ
    lis[0] = v[0]; // ù ������ ���� �ϰ� length �� 1��
    int length = 1;

    for (int i = 1; i < v.size(); i++) {
        auto s = lis.begin();
        auto e = s + length;
        auto it = lower_bound(s, e, v[i]);

        if (it == e) {
            lis[length++] = v[i];
        }
        else {
            *it = v[i];
        }
    }

    return length;

}


int main()
{
    fast_io();

    int n;
    cin >> n;

    vector<int> A;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    // ������ ���� �����ϴ� ���� �κм��� ���̸� ���ϴ� ���̹Ƿ�
    // reverse�� ������
    reverse(A.begin(), A.end());

    cout << LIS(A) << "\n";

    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    // unique values or same values
    return 0;
}