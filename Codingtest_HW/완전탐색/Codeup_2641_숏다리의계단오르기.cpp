#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int n;
int result;

// ¿ÏÀü Å½»ö
void cnt_step(int total, int check3)
{
    check3--;
    //cout << check3 << "\n";

    if(n == 0) 
        return;
    if (n - total >= 1) cnt_step(total + 1, check3);
    if (n - total >= 2) cnt_step(total + 2, check3);
    if (n - total >= 3 && check3 < 0) cnt_step(total + 3, 2);
    else if (total == n) result += 1;
}

int main()
{
	cin >> n;

    cnt_step(0, 0);
	cout << result;
	return 0;
}