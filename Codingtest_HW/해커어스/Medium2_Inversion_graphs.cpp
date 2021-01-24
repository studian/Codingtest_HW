#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LongestIncreasingSubsequenceLength(vector<int>& v)
{
    if (v.size() == 0)
        return 0;

    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail  

    tail[0] = v[0];

    for (int i = 1; i < v.size(); i++) {

        // Do binary search for the element in  
        // the range from begin to begin + length 
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);

        // If not present change the tail element to v[i]  
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }

    return length;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> A;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    reverse(A.begin(), A.end());

    cout << LongestIncreasingSubsequenceLength(A) << "\n";

    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    // unique values or same values
    return 0;
}