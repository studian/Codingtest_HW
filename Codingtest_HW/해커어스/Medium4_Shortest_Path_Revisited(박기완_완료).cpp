//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include <stdio.h>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

struct Info {
    int nowK; //k���Ƚ��
    int start;  //�ش簣�� �����
    int dest; //�ش簣�� ������ 
    long long int weight; //��������ġ
};

struct CMP {
    bool operator() (const Info& a, const Info& b) const {
        return a.weight > b.weight;
    }
};


//��������Ʈ�� ǥ��  
vector<pair<int, long long int> > edges[100001];
priority_queue<Info, vector<Info>, CMP > que;
int n, m, k;

//����� (�ش� ������ �����ϴµ� �ʿ��� ��밪 )
long long int result[100001];

//���� ���ͽ�Ʈ�� ��ã�� ��� Ȯ�� �ȵ� ���
set<int> remainNode;

long long int dp[19][100001];

void find(int node) {

    //1������ ����� ���� �켱����ť�� �ֱ�
    for (int i = 0; i < edges[node].size(); i++) {
        //�켱����ť��   ������, ������, ����ġ �������� �ֱ� (1����忡 ����) 
        que.push({ 0, node,edges[node][i].first,edges[node][i].second });

        if (k > 0) que.push({ 1, node,edges[node][i].first,0 });
    }

    //���������������
    while (!que.empty() && remainNode.size() > 0) {
        //������
        Info ft = que.top();
        que.pop();

        //�����ְ� ���Ȯ���� ��尡 �ƴ϶�� �·� ����ġ�� ���� �ϰ� �ش���� ��ã��Ϸ�ó��
        auto iter = remainNode.find(ft.dest);
        if (iter != remainNode.end()) {
            result[ft.dest] = ft.weight;
            remainNode.erase(iter);
        }

        for (int j = 0; j < edges[ft.dest].size(); j++) {
            //auto iter1 = remainNode.find(edges[ft.dest][j].first);
            //if (iter1 == remainNode.end()) continue;
            if (edges[ft.dest][j].first == ft.start) continue;

            //���⼭ �ݺ��� ���� ���δٸ� ..
            //k�� ������ ����ġ�� �� ū���� ������ �ȳֱ�

            if (ft.nowK < k) {
                //�̹� ���� �� ������ Ǫ��
                if (dp[ft.nowK][edges[ft.dest][j].first] > ft.weight + edges[ft.dest][j].second) {

                    dp[ft.nowK][edges[ft.dest][j].first] = ft.weight + edges[ft.dest][j].second;

                    que.push({ ft.nowK, ft.dest,edges[ft.dest][j].first, ft.weight + edges[ft.dest][j].second });

                }
                if (dp[ft.nowK + 1][edges[ft.dest][j].first] > ft.weight) {
                    dp[ft.nowK + 1][edges[ft.dest][j].first] = ft.weight;
                    que.push({ ft.nowK + 1, ft.dest,edges[ft.dest][j].first, ft.weight + 0 });
                }
            }
            else {
                if (dp[ft.nowK][edges[ft.dest][j].first] > ft.weight + edges[ft.dest][j].second) {

                    dp[ft.nowK][edges[ft.dest][j].first] = ft.weight + edges[ft.dest][j].second;

                    que.push({ ft.nowK, ft.dest,edges[ft.dest][j].first, ft.weight + edges[ft.dest][j].second });

                }
            }
        }

    }
}

int main()
{
    cin >> n >> m >> k;
    //scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 1e18;
        }
    }

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
        //printf("%lld ", result[i]);
    }

    return 0;
}