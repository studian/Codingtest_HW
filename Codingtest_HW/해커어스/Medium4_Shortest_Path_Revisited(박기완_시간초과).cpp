//#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

struct Info {
    int nowK; //k사용횟수
    int start;  //해당간선 출발지
    int dest; //해당간선 도착지 
    int weight; //누적가중치
};

struct CMP {
    bool operator() (const Info& a, const Info& b) const {
        return a.weight > b.weight;
    }
};


//인접리스트로 표현  
vector<pair<int, int> > edges[100001];
priority_queue<Info, vector<Info>, CMP > que;
int n, m, k;

//결과값 (해당 선까지 도달하는데 필요한 비용값 )
int result[100001];

//아직 다익스트라 길찾기 경로 확정 안된 노드
set<int> remainNode;

void find(int node) {

    //1번노드와 연결된 정보 우선순위큐에 넣기
    for (int i = 0; i < edges[node].size(); i++) {
        //우선순위큐에   시작지, 도착지, 가중치 간선정보 넣기 (1번노드에 대해) 
        que.push({ 0, node,edges[node][i].first,edges[node][i].second });

        if (k > 0) que.push({ 1, node,edges[node][i].first,0 });
    }

    //비어있지않은동안
    while (!que.empty() && remainNode.size() > 0) {
        //꺼내서
        Info ft = que.top();
        que.pop();

        //꺼낸애가 경로확정된 노드가 아니라면 걔로 가중치값 세팅 하고 해당노드는 길찾기완료처리
        auto iter = remainNode.find(ft.dest);
        if (iter != remainNode.end()) {
            result[ft.dest] = ft.weight;
            remainNode.erase(iter);
        }

        for (int j = 0; j < edges[ft.dest].size(); j++) {
            //auto iter1 = remainNode.find(edges[ft.dest][j].first);
            //if (iter1 == remainNode.end()) continue;
            if (edges[ft.dest][j].first == ft.start) continue;

            if (ft.nowK < k) {
                que.push({ ft.nowK, ft.dest,edges[ft.dest][j].first, ft.weight + edges[ft.dest][j].second });
                que.push({ ft.nowK + 1, ft.dest,edges[ft.dest][j].first, ft.weight + 0 });
            }
            else {
                que.push({ ft.nowK, ft.dest,edges[ft.dest][j].first, ft.weight + edges[ft.dest][j].second });
            }
        }

    }
}

int main()
{
    //scanf("%d %d %d", &n, &m, &k);
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        //scanf("%d %d %d", &start, &end, &weight);
        edges[start].push_back({ end,weight });
        edges[end].push_back({ start,weight });
    }

    for (int i = 2; i <= n; i++) {
        remainNode.insert(i);
    }
    find(1);

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
        //printf("%d ", result[i]);
    }

    return 0;
}