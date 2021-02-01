#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>

int tree[3000010];
int leafStartPos = 1;
int n, k;

// index�ѱ��.. ����ġ ���� ���� �ö󰡸� Ʈ�� ���� 
void updateTree(int index) {

    int i = index >> 1;

    for (; i >= 1; i = i >> 1) {
        //�ܸ� �ٷ� �� ������ 1������ �ٽ� ���� 
        if ((leafStartPos >> 1) <= i) {
            tree[i] = (tree[i * 2] == k ? 1 : 0) + (tree[i * 2 + 1] == k ? 1 : 0);
        }
        //������ 1������ ä�����Ű��� ��ġ�¹������ ����
        else {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
}

void printTree() {
    //Ȯ��  
    for (int i = 1; i < (leafStartPos + n); i++) {
        printf("%d ", tree[i]);
    }
    printf("\n");
}


void find(int index, int nows, int nowe, int queryStart, int queryEnd, int& sum, int& pos) {
    if (nows > queryEnd || nowe < queryStart || sum == 0) return;

    if (nows == nowe) {
        //�ܸ�����..  0 ���� 1���� ���� ���
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
            //�����ġ���� ã��

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

    /*n�� 4��..
       -
     -   -
    4 5 6 7

    n�� 5~8�̸�..
          -
       -       -
     -   -   -   -
    - - - - - - - -    8~..
    */
    //n���� ���� �Էµ� �迭�� ������ġ ���� 
    for (; leafStartPos < n; leafStartPos = leafStartPos << 1);

    //������ �Է���  bottom up���·� Ʈ�� ����
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[leafStartPos + i]);
    }
    for (int i = leafStartPos - 1; i >= 1; i--) {
        //�ܸ� �ٷ� ������ 1�� ���� ���� ���� ���̺� �����ϰ� 
        if ((leafStartPos >> 1) <= i) {
            tree[i] = (tree[i * 2] == k ? 1 : 0) + (tree[i * 2 + 1] == k ? 1 : 0);
        }
        //����������ʹ� �ܼ� ��
        else {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    //printTree();

    //������ 
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int type; //���� ���� 
        int left, right, pos; //(1��)  ����, �������ε���,  k�� �´�  pos �ֳ� üũ 
        int index, value; //(2��)  �ε���, �ٲܰ� 
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