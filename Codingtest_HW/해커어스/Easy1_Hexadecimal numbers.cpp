#include <iostream>
#include <algorithm>

using namespace std;

int f(int x) {
    int sum = 0;
    while (x > 0) {
        sum = sum + x % 16;
        x = x / 16;
    }
    return sum;
}

int gcd(int x, int y) {
    int minV = min(x, y);

    for (; minV >= 1; minV--) {
        if (x % minV == 0 && y % minV == 0) {
            return minV;
        }

    }

    return minV;
}

int gcd1(int x, int y) {
    int r = x % y;
    if (r == 0) return y;
    return gcd1(y, r);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        for (; l <= r; l++) {
            if (gcd1(l, f(l)) > 1) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}