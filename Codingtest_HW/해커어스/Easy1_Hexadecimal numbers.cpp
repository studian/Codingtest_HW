//#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int t; cin >> t;

    while (t--) {

        int l, r, sum, count = 0; cin >> l >> r;

        for (int i = l; i <= r; i++) {

            int x = i;

            sum = 0;

            while (x > 0) {

                sum += x % 16;

                x = x / 16;

            }

            //if (gcd(i, sum) > 1)count++;

        }

        cout << count << endl;

    }

    return 0;

}