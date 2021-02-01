// Write your code here
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int LIS(vector<int>& v)
{
    if (v.size() == 0) return 0;

    vector<int> lis(v.size(), 0); // 데이터 v배열 크기 만큼 만들고, 0으로 초기화
    lis[0] = v[0]; // 첫 데이터 같게 하고 length 는 1로
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

    // 문제는 단조 감소하는 최장 부분수열 길이를 구하는 것이므로
    // reverse로 뒤집기
    reverse(A.begin(), A.end());

    cout << LIS(A) << "\n";

    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    // unique values or same values
    return 0;
}