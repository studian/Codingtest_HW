#include <iostream>
using namespace std;

int money[11] = { 0, };
int money_idx[11] = { 0, };

int main()
{
    int target, num;

    cin >> target;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cin >> money[i];
    }

    /*
    while (num>0)
    {
        int mod = target / money[num];
        ans += mod;
        target -= (mod * money[num]);
        --num;
    }
    */
    // ¿ÏÀü Å½»ö
    int last_ans = 1000000000;
    for (int number = num; number > 0; --number)
    {
        int ans = 0;
        money_idx[number] = 1;
        int mod = target / money[number];
        ans += mod;
        target -= (mod * money[number]);

        int number2 = num;
        while (number2 > 0 && money_idx[number2] == 0)
        {
            int mod2 = target / money[number2];
            ans += mod2;
            target -= (mod2 * money[number2]);
            --number2;
        }
        last_ans = min(ans, last_ans);
        last_ans = min(ans, last_ans);
    }    

    cout << last_ans;
}