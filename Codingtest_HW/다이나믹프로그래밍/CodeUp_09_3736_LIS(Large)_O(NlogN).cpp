#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, lis[1001], len, num;
int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        if (*lowerPos == 0) len++;
        *lowerPos = num;
        for (int j = 0; j < n; j++) {
            printf("%d ", lis[j]);
        }
        printf("\n");
    }
    printf("%d", len);

    return 0;
}

//이해안감