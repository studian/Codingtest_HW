#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
int n, a[1001], cnt[1001];

int ON2()
{
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int maxValue = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && maxValue < cnt[j]) maxValue = cnt[j];
        }
        cnt[i] = maxValue + 1;
        ret = max(ret, cnt[i]);
    }

    return ret;
}

int main() {
    cin >> n;
    //scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        //scanf("%d", &a[i]);
        cin >> a[i];
    }
    
    printf("%d\n", ON2());
}