#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main()
{

    /*int n = 9;
    while (n % 3 == 0) {
       n = n / 3;
    }

    if (n != 1) {
       throw -1;
    }*/

    int n;
    n = 9;

    if (n == 0) throw - 1;
    //3�� 20��  (unsigned...   �ܼ�int�� 3�� 19��.. unsigned���� 3��20��.. 
    if (3486784401 % n != 0) throw - 1;

    int i = 3;
    int j = 5;

    if (i <= j) {
        j = j - i;
        i = 0;

        if (j % 2 == 0) {
            printf("white");
        }
        else {
            printf("black");
        }
    }
    else {
        i = i - j;
        j = 0;
        if (i % 2 == 0) {
            printf("white");
        }
        else {
            printf("black");
        }
    }
    return 0;
}