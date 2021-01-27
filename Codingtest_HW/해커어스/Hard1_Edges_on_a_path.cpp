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

//총 노드 갯수
int nodeCnt;

//인접리스트로 그래프 표현
vector<int> graph[100001];
vector<pair<int, int>> edgeInfo;

//dfs탐색시 방문여부용
int visited[100001];


//문제에 주어진 두 노드
int node1, node2;

//간선 사용 최대 횟수
int maxVisitCntEdge;

//간선별 담긴 방문횟수정보 (최종적으로 갯수 세서 출력할예정)
map<long long int, int> resultInfo;

//a-b간선정보를 longlongint 형태로 변환.  a가 1 b가 2면 0x0000000100000002
long long int convertEdgeToValue(int a, int b) {
    if (a > b) {
        int temp = b;
        b = a;
        a = temp;
    }

    //항상 a<=b관계만들어놓고
    return (long long int)a << 32 | b;
}

//단순히 완전탐색해서 모든경로 탐색하며  목적지 도달시 맵에 넣을 예정
void dfs(int nowNode, vector<int> nowPath) {

    //경로 추가
    nowPath.push_back(nowNode);
    //방문 처리
    visited[nowNode] = 1;

    if (nowNode == node2) {

        //시작부터 목적지까지의 정보들을 resultInfo에 다 담음 
        for (int i = 0; i < nowPath.size() - 1; i++) {
            int start = nowPath[i];
            int dest = nowPath[i + 1];

            long long int edgeInfoValue = convertEdgeToValue(start, dest);
            //아마 원소없으면 0으로 셋팅되서 거기 ++되지않나?
            resultInfo[edgeInfoValue]++;
            if (maxVisitCntEdge < resultInfo[edgeInfoValue]) maxVisitCntEdge = resultInfo[edgeInfoValue];
        }

        //방문해제처리
        visited[nowNode] = 0;

        return;
    }

    for (int i = 0; i < graph[nowNode].size(); i++) {

        //방문한적 없다면 해당노드 탐색시작(탐색시작시 함수내부에서 방문처리, 경로추가 함)
        if (visited[graph[nowNode][i]] == 0) {
            dfs(graph[nowNode][i], nowPath);
        }

    }
    //방문해제처리
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

    //반복문 돌면서  간선 최대방문횟수랑 일치하는 것들 갯수 뽑아 출력
    int result = 0;
    for (auto& iter : edgeInfo) {
        long long int edgeInfoValue = convertEdgeToValue(iter.first, iter.second);
        if (resultInfo[edgeInfoValue] == maxVisitCntEdge) {
            ++result;
        }
    }

    printf("%d ", result);

}