/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
   int num;
   cin >> num;                              // Reading input from STDIN
   cout << "Input number is " << num << endl;      // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//�� ��� ����
int nodeCnt;

//��������Ʈ�� �׷��� ǥ��
vector<int> graph[100001];
vector<pair<int, int>> edgeInfo;

//dfsŽ���� �湮���ο�
int visited[100001];


//������ �־��� �� ���
int node1, node2;

//���� ��� �ִ� Ƚ��
int maxVisitCntEdge;

//������ ��� �湮Ƚ������ (���������� ���� ���� ����ҿ���)
map<long long int, int> resultInfo;

//a-b���������� longlongint ���·� ��ȯ.  a�� 1 b�� 2�� 0x0000000100000002
long long int convertEdgeToValue(int a, int b) {
    if (a > b) {
        int temp = b;
        b = a;
        a = temp;
    }

    //�׻� a<=b���踸������
    return (long long int)a << 32 | b;
}

//�ܼ��� ����Ž���ؼ� ����� Ž���ϸ�  ������ ���޽� �ʿ� ���� ����
void dfs(int nowNode, vector<int> nowPath) {

    //��� �߰�
    nowPath.push_back(nowNode);
    //�湮 ó��
    visited[nowNode] = 1;

    if (nowNode == node2) {

        //���ۺ��� ������������ �������� resultInfo�� �� ���� 
        for (int i = 0; i < nowPath.size() - 1; i++) {
            int start = nowPath[i];
            int dest = nowPath[i + 1];

            long long int edgeInfoValue = convertEdgeToValue(start, dest);
            //�Ƹ� ���Ҿ����� 0���� ���õǼ� �ű� ++�����ʳ�?
            resultInfo[edgeInfoValue]++;
            if (maxVisitCntEdge < resultInfo[edgeInfoValue]) maxVisitCntEdge = resultInfo[edgeInfoValue];
        }

        //�湮����ó��
        visited[nowNode] = 0;

        return;
    }

    for (int i = 0; i < graph[nowNode].size(); i++) {

        //�湮���� ���ٸ� �ش��� Ž������(Ž�����۽� �Լ����ο��� �湮ó��, ����߰� ��)
        if (visited[graph[nowNode][i]] == 0) {
            dfs(graph[nowNode][i], nowPath);
        }

    }
    //�湮����ó��
    visited[nowNode] = 0;

}



int main()
{
    int edge;
    cin >> nodeCnt >> edge;
    cin >> node1 >> node2;

    for (int i = 1; i <= edge; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        edgeInfo.push_back({ x,y });
    }

    vector<int> nowPath;
    dfs(node1, nowPath);

    //�ݺ��� ���鼭  ���� �ִ�湮Ƚ���� ��ġ�ϴ� �͵� ���� �̾� ���
    int result = 0;
    for (auto& iter : edgeInfo) {
        long long int edgeInfoValue = convertEdgeToValue(iter.first, iter.second);
        if (resultInfo[edgeInfoValue] == maxVisitCntEdge) {
            ++result;
        }
    }

    printf("%d ", result);

}