// Write your code here
#include <iostream>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional>
//#include<bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;

//template<class T1, class T2>
//ostream& operator << (ostream& out, pair<T1, T2> p)
//{
//    out << p.first << ' ' << p.second;
//    return out;
//}
//
//template<class T1, class T2>
//istream& operator >> (istream& in, pair<T1, T2>& p)
//{
//    in >> p.first >> p.second;
//    return in;
//}
//
//template<class T>
//istream& operator >> (istream& in, vector<T>& v)
//{
//    for (auto& x : v)
//        in >> x;
//    return in;
//}
//
//template<class T>
//ostream& operator << (ostream& out, vector<vector<T>>& v)
//{
//    for (auto& x : v)
//        out << x << '\n';
//    return out;
//}
//
//template<class T>
//ostream& operator << (ostream& out, vector<T>& v)
//{
//    for (auto x : v)
//        out << x << ' ';
//    return out;
//}

#define ll long long
#define all(sdk) sdk.begin(),sdk.end()
#define mll map<int, int>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define hell 1000000007
#define endl '\n'
#define vvll vector<vector<int> >
#define vll vector<int>
#define mint map<int,int> 
#define sz(x) (int)x.size()
#define sll set<int>
#define pii pair<int,int>
#define F first
#define S second

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
#define maxn 200005
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    ios;
    int n, x;
    cin >> n >> x;
    ordered_set s;
    int a[n + 1];
    rep(i, 1, n + 1) {
        cin >> a[i];
        if (a[i] == x) s.insert(i);
    }
    int qq;
    cin >> qq;
    while (qq--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            int x = s.order_of_key(l);
            x += k;
            if (x > (int)(s.size())) {
                cout << "-1\n";
            }
            else {
                int ans = *(s.find_by_order(x - 1));
                if (ans > r) cout << "-1\n";
                else cout << ans << "\n";
            }
        }
        else {
            int in, va;
            cin >> in >> va;
            if (a[in] == x) s.erase(in);
            if (va == x) s.insert(in);
            a[in] = va;
        }
    }
    return 0;
}