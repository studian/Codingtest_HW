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
        // ����(bhgin)���� length ���� ���� ������ arr[i] ã�� �����˻�
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
        // ����(bhgin)���� length ���� ���� ������ v[i] ã�� �����˻�
        auto s = lis.begin();
        auto e = lis.begin() + length;
        auto it = lower_bound(s, e, v[i]);

        cout << i << " " << length << " " << v[i] << "\n";

        // � ��������(������->ū��)���� ���ĵ� �迭�� s~e ���������� 
        // d���� 1) ���ų� 
        //       2) (�������� ������) ���ʷ� ū ���� �˻��ϰ� ������ 
        // lower_bound ���
        // �� �˻�: auto it = lower_bound(s, e, d); �Ǵ� lower_bound(array.begin(), array.end(), �˻��� ��);
        // �� �˻��� ��ġ ��ȯ: int idx = (lower_bound(array.begin(), array.end(), �˻��� ��) - array.begin());

        // ���� �˻��� array �迭 ������ s~e ���������� d���� ��� ���� ���� ���, 
        // auto it = lower_bound(s, e, d);
        // *it�� 0 ��, it �� �˻����� e�� �Ǿ��
        if (it == lis.begin() + length) { // lis �迭 ������ �˻���(v[i])���� ��� ���� ���� ���, lis �迭�� v[i]�߰�
            lis[length++] = v[i];
            cout << "#in: ";
            for (int j = 0; j < lis.size(); j++) {
                cout << lis[j] << " ";
            }
            cout << "\n";
        }
        else {// lis �迭 ������ �˻���(v[i])�� ���ų�, ���ʷ� ū���� �ִ� ���, ��, �˻� ��(v[i])�� �� �۴ٸ�, �ش� idx�� �迭���� v[i]�� ����
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