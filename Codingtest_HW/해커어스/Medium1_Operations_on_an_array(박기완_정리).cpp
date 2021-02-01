#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>

int tree[3000010];
int leafStartPos = 1;
int n, k;

// index넘기면.. 그위치 기준 위로 올라가며 트리 수정 
void updateTree(int index) {

    int i = index >> 1;

    for (; i >= 1; i = i >> 1) {
        //단말 바로 윗 레벨은 1갯수로 다시 세고 
        if ((leafStartPos >> 1) <= i) {
            tree[i] = (tree[i * 2] == k ? 1 : 0) + (tree[i * 2 + 1] == k ? 1 : 0);
        }
        //그위는 1갯수로 채워진거갖고 합치는방식으로 구성
        else {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
}

void printTree() {
    //확인  
    for (int i = 1; i < (leafStartPos + n); i++) {
        printf("%d ", tree[i]);
    }
    printf("\n");
}


void find(int index, int nows, int nowe, int queryStart, int queryEnd, int& sum, int& pos) {
    if (nows > queryEnd || nowe < queryStart || sum == 0) return;

    if (nows == nowe) {
        //단말노드니..  0 인지 1인지 따로 계산
        int temp = (tree[index] == k ? 1 : 0);
        if (temp == sum) {
            pos = nows;
            sum -= temp;
            return;
        }
        else {
            sum -= temp;
            return;
        }
    }


    if (queryStart <= nows && nowe <= queryEnd) {
        if (tree[index] < sum) {
            sum = sum - tree[index];
            return;
        }
        else {
            //어느위치인지 찾기

        }
    }


    int mid = (nows + nowe) / 2;
    find(index * 2, nows, mid, queryStart, queryEnd, sum, pos);
    if (sum != 0) {
        find(index * 2 + 1, mid + 1, nowe, queryStart, queryEnd, sum, pos);
    }
}

int main()
{
    scanf("%d %d", &n, &k);

    /*n이 4면..
       -
     -   -
    4 5 6 7

    n이 5~8이면..
          -
       -       -
     -   -   -   -
    - - - - - - - -    8~..
    */
    //n값에 따른 입력된 배열들 시작위치 잡음 
    for (; leafStartPos < n; leafStartPos = leafStartPos << 1);

    //데이터 입력후  bottom up형태로 트리 구성
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[leafStartPos + i]);
    }
    for (int i = leafStartPos - 1; i >= 1; i--) {
        //단말 바로 윗노드는 1의 갯수 직접 세며 테이블 구성하고 
        if ((leafStartPos >> 1) <= i) {
            tree[i] = (tree[i * 2] == k ? 1 : 0) + (tree[i * 2 + 1] == k ? 1 : 0);
        }
        //그윗노드들부터는 단순 합
        else {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    //printTree();

    //질문수 
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int type; //질문 유형 
        int left, right, pos; //(1번)  왼쪽, 오른쪽인덱스,  k랑 맞는  pos 있나 체크 
        int index, value; //(2번)  인덱스, 바꿀값 
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %d", &left, &right, &pos);
            int sum = pos;
            int ans = -1;
            find(1, 1, leafStartPos, left, right, sum, ans);
            printf("%d\n", ans);
        }
        else {
            scanf("%d %d", &index, &value);
            tree[leafStartPos + index - 1] = value;
            updateTree(leafStartPos + index - 1);

            //printTree();
        }
    }

}