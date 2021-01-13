#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef int element;


typedef struct Node {
    element data;
    struct Node* pLeft;
    struct Node* pRight;
}Node;

void print_levelorder(Node* node);
int getNodeHeight(Node* node);
int getNodeCNT(Node* node);

Node* getMostLeftNode_inRight(Node* node);
Node* getMostRightNode_inLeft(Node* node);


Node* getLeftNodePtr(Node* node);
Node* getRightNodePtr(Node* node);
element getRightNodeElement(Node* node);
int maxValue(int a, int b);
void getNodeCapacity(Node* node, int& SumElements);
int getNodeCapacityT(Node* node);

int main()
{
    /*
    트리모습
          8
       3      12
      1   6  10   14
       4
         5
    */
    Node* node8 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));
    Node* node12 = (Node*)malloc(sizeof(Node));
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node6 = (Node*)malloc(sizeof(Node));
    Node* node10 = (Node*)malloc(sizeof(Node));
    Node* node14 = (Node*)malloc(sizeof(Node));
    Node* node4 = (Node*)malloc(sizeof(Node));
    Node* node5 = (Node*)malloc(sizeof(Node));


    node8->data = 8; node8->pLeft = node3; node8->pRight = node12;
    node3->data = 3; node3->pLeft = node1; node3->pRight = node6;
    node12->data = 12; node12->pLeft = node10; node12->pRight = node14;
    node1->data = 1; node1->pLeft = NULL; node1->pRight = NULL;
    node6->data = 6; node6->pLeft = node4; node6->pRight = NULL;
    node10->data = 10; node10->pLeft = NULL; node10->pRight = NULL;
    node14->data = 14; node14->pLeft = NULL; node14->pRight = NULL;
    node4->data = 4; node4->pLeft = NULL; node4->pRight = node5;
    node5->data = 5; node5->pLeft = NULL; node5->pRight = NULL;

    Node* root = node8;

    print_levelorder(root);

    printf("getNodeHeight: %d\n", getNodeHeight(root));

    int SumElements = 0;
    getNodeCapacity(root, SumElements);

    printf("getNodeCapacity: %d\n", SumElements);
    printf("getNodeCapacityT: %d\n", getNodeCapacityT(root));
    printf("getNodeCNT: %d\n", getNodeCNT(root));

    Node* MostLeftNode_inRight = getMostLeftNode_inRight(root->pRight);
    printf("getMostLeftNode_inRight: %d\n", MostLeftNode_inRight->data);

    Node* MostRightNode_inLeft = getMostRightNode_inLeft(root->pRight);
    printf("getMostRightNode_inLeft: %d\n", MostRightNode_inLeft->data);
}

void print_levelorder(Node* node)
{
    //큐에 넣고 순회
    queue<Node*>que;
    que.push(node);
    printf("\n================================\n");

    while (!que.empty()) {
        Node* pFront = que.front();
        que.pop();

        printf("%d ", pFront->data);


        if (pFront->pLeft)   que.push(pFront->pLeft);
        if (pFront->pRight)  que.push(pFront->pRight);
    }
    printf("\n================================\n");
}

Node* getLeftNodePtr(Node* node)
{
    return node->pLeft;
}

Node* getRightNodePtr(Node* node)
{
    return node->pRight;
}

element getRightNodeElement(Node* node)
{
    return node->data;
}

int maxValue(int a, int b)
{
    return (a >= b) ? a : b;
}


int getNodeHeight(Node* node)
{
    /*
    if (node == NULL) return 0;
    if (node->pLeft == NULL && node->pRight == NULL) return 1;
    return maxValue(getNodeHeight(node->pLeft), getNodeHeight(node->pRight)) +1;
    */

    int leftHight = 0;
    int RightHight = 0;
    if (node->pLeft != NULL)
    {
        leftHight = getNodeHeight(node->pLeft);
    }

    if (node->pRight != NULL)
    {
        RightHight = getNodeHeight(node->pRight);
    }

    return maxValue(leftHight, RightHight)+1;
}

void getNodeCapacity(Node* node, int& SumElements)
{
    /*
    
    if (node->pLeft == NULL && node->pRight == NULL) return 1;
    return maxValue(getNodeHeight(node->pLeft), getNodeHeight(node->pRight)) +1;
    */
    if (node == NULL) return;

    SumElements += node->data;

    if (node->pLeft != NULL)
    {
        getNodeCapacity(node->pLeft, SumElements);
    }

    if (node->pRight != NULL)
    {
        getNodeCapacity(node->pRight, SumElements);
    }
}

int getNodeCapacityT(Node* node)
{
    if (node == NULL) return 0;
    if (node->pLeft == NULL && node->pRight == NULL) return node->data; 
    return getNodeCapacityT(node->pLeft) + getNodeCapacityT(node->pRight) + node->data;
}

int getNodeCNT(Node* node)
{
    if (node == NULL) return 0;
    if (node->pLeft == NULL && node->pRight == NULL) return 1;

    return getNodeCNT(node->pLeft) + getNodeCNT(node->pRight);
}

Node* getMostLeftNode_inRight(Node* node)
{
    if (node == NULL) return node;
    if (node->pLeft == NULL) return node;

    return getMostLeftNode_inRight(node->pLeft);
}

Node* getMostRightNode_inLeft(Node* node)
{
    if (node == NULL) return node;
    if (node->pRight == NULL) return node;

    return getMostRightNode_inLeft(node->pRight);
}