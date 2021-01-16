#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
int n, a[1001], dp[1001];

int ON2()
{
    int ret = dp[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[i] < dp[j]+1) dp[i] = dp[j] + 1;
        }
        ret = max(ret, dp[i]);
    }

    return ret;
}

int main() {
    cin >> n;
    //scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        //scanf("%d", &a[i]);
        cin >> a[i];
        dp[i] = 1; // dp배열 1로 초기화
    }
    
    printf("%d\n", ON2());
}