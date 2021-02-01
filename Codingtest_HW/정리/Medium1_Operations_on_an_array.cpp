// Write your code here
#include <iostream>
#include <vector>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*
int LIS(vector<int>& arr)
{
    if (arr.empty() || arr.size() == 0) return 0;

    vector<int> lis(arr.size(), 0);
    int length = 1;

    lis[0] = arr[0]; 
    for (int i = 1; i < arr.size(); i++) {
        // 시작(bhgin)부터 length 까지 범위 내에서 arr[i] 찾는 이진검색
        auto s = arr.begin();
        auto e = arr.begin() + length;
        auto it = lower_bound(s, e, arr[i]); 
        cout << "0: " << i << " " << arr[i] << " " << *it << "\n";

        // If not present change the tail element to v[i]  
        if (it == lis.begin() + length) {
            lis[length++] = arr[i];

            cout << "#1: ";
            for (int j = 0; j < lis.size(); j++) {
                cout << lis[j] << " ";
            }
            cout << "\n";
        }            
        else {
            *it = arr[i];
            cout << "#2: ";
            for (int j = 0; j < lis.size(); j++) {
                cout << lis[j] << " ";
            }
            cout << "\n";
        }
            

        
    }
    return length;
}

int main()
{
    fast_io();

    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    cout << LIS(arr) << "\n";
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    // unique values or same values
    return 0;
}
*/


int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0)
        return 0;

    std::vector<int> lis(v.size(), 0);
    int length = 1; // always points empty slot in tail  

    lis[0] = v[0];

    for (int i = 1; i < v.size(); i++) {
        // 시작(bhgin)부터 length 까지 범위 내에서 v[i] 찾는 이진검색
        auto s = lis.begin();
        auto e = lis.begin() + length;
        auto it = lower_bound(s, e, v[i]);

        cout << i << " " << length << " " << v[i] << "\n";

        // 어떤 오름차순(작은수->큰수)으로 정렬된 배열의 s~e 범위내에서 
        // d보다 1) 같거나 
        //       2) (같은값이 없으면) 최초로 큰 값을 검색하고 싶으면 
        // lower_bound 사용
        // 값 검색: auto it = lower_bound(s, e, d); 또는 lower_bound(array.begin(), array.end(), 검색할 값);
        // 값 검색한 위치 반환: int idx = (lower_bound(array.begin(), array.end(), 검색할 값) - array.begin());

        // 만약 검색할 array 배열 내에서 s~e 범위내에서 d보다 모든 값이 작은 경우, 
        // auto it = lower_bound(s, e, d);
        // *it는 0 즉, it 는 검색범위 e가 되어됨
        if (it == lis.begin() + length) { // lis 배열 내에서 검색값(v[i])보다 모든 값이 작은 경우, lis 배열에 v[i]추가
            lis[length++] = v[i];
            cout << "#in: ";
            for (int j = 0; j < lis.size(); j++) {
                cout << lis[j] << " ";
            }
            cout << "\n";
        }
        else {// lis 배열 내에서 검색값(v[i])과 같거나, 최초로 큰값이 있는 경우, 즉, 검색 값(v[i])이 더 작다면, 해당 idx의 배열값을 v[i]로 변경
            cout << "@@\n";
            cout << *it << " " << v[i] << "\n";
            cout << it-s << " " << i << "\n";

            *it = v[i];

            cout << "#up: ";
            for (int j = 0; j < lis.size(); j++) {
                cout << lis[j] << " ";
            }
            cout << "\n";
        }
            
    }

    return length;
}

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
        cout << "data input :";
        int a;
        cin >> a;
        A.push_back(a);
    }
    
    for (auto a : A) {
        cout << a << " ";
    }
    cout << "\n";


    /*auto s = A.begin();
    auto e = A.end();
    for (int i = 0; i < n; i++) {
        cout << "\n data search";
        int d;
        cin >> d;

        
        auto s = A.begin();
        auto e = A.end();
        
        auto it = uper_bound(s, e, d);

        cout << *it << " " << it-s << "\n";
    }*/
    

    //reverse(A.begin(), A.end());

    cout << LIS(A) << "\n";

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    // unique values or same values
    return 0;
}