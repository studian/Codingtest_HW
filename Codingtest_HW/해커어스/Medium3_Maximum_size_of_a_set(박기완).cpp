#include <queue>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

vector<int> graph[200001];
int memo[200001];
int visited[200001];

int dfs(int nowNode) {


    if (memo[nowNode]) return memo[nowNode];


    //더이상 연결된대 없다면 1리턴 
    int mmax = 0;
    for (int i = 0; i < graph[nowNode].size(); i++) {
        int t = dfs(graph[nowNode][i]);
        if (mmax < t) {
            mmax = t;
        }
    }
    mmax++;
    memo[nowNode] = mmax;
    return mmax;
}
int main()
{
    int nodeCnt, edgeCnt;
    scanf("%d %d", &nodeCnt, &edgeCnt);

    for (int i = 1; i <= edgeCnt; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
    }

    int mmax = 0;
    for (int i = 1; i <= nodeCnt; i++) {
        int t = dfs(i);
        if (mmax < t) {
            mmax = t;
        }
    }
    printf("%d", mmax);

    return 0;
}