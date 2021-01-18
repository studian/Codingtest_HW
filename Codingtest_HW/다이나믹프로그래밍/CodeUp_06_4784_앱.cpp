#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int N; // 앱 개수, 1 <= N <= 100
int M; // 확보 해야할 메모리크기, 1 <= W <= 10 000 000

int m[101]; // 앱 비활성화시 앱 메모리양
int c[101]; // 앱 비활성화시 앱 비용

//cache[i][j]는 i위치부터 j비용으로 만들수 있는 최대 메모리 크기
int cache[101][10001];

int calc_memory(int idx, const int total_cost) {
    if (cache[idx][total_cost] != -1) return cache[idx][total_cost];

    if (idx == N+1)
        return 0;

    //메모이제이션 활용
    int ret = cache[idx][total_cost];

    //기저 사례 : 이미 탐색이 완료된 경우
    if (ret != -1)
        return ret;

    //현재 앱을 비활성화 시키지 않은 경우
    ret = calc_memory(idx + 1, total_cost);

    //현재 앱을 비활성화 시키는 경우
    if (c[idx] <= total_cost)
        //현재 앱을 비활성화 시키지 않은 경우와 비교하여 더 큰 메모리를 선택
        ret = max(ret, m[idx] + calc_memory(idx + 1, total_cost - c[idx]));

    return cache[idx][total_cost] = ret;
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> m[i];
    for (int i = 1; i <= N; i++)
        cin >> c[i];

    //메모이제이션을 활용하기 위해 초기화
    memset(cache, -1, sizeof(cache));

    int ret = 0;

    //가능한 최대 코스트는 10000까지 탐색을 진행하도록 하자.
    for (int i = 0; i < 10001; i++) {
        ret = calc_memory(1, i);
        if (ret >= M) {
            cout << i;
            break;
        }
    }

    return 0;
}

// 틀림 (배낭문제와 같은거 같은데...)