#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int N; // �� ����, 1 <= N <= 100
int M; // Ȯ�� �ؾ��� �޸�ũ��, 1 <= W <= 10 000 000

int m[101]; // �� ��Ȱ��ȭ�� �� �޸𸮾�
int c[101]; // �� ��Ȱ��ȭ�� �� ���

//cache[i][j]�� i��ġ���� j������� ����� �ִ� �ִ� �޸� ũ��
int cache[101][10001];

int calc_memory(int idx, const int total_cost) {
    if (cache[idx][total_cost] != -1) return cache[idx][total_cost];

    if (idx == N+1)
        return 0;

    //�޸������̼� Ȱ��
    int ret = cache[idx][total_cost];

    //���� ��� : �̹� Ž���� �Ϸ�� ���
    if (ret != -1)
        return ret;

    //���� ���� ��Ȱ��ȭ ��Ű�� ���� ���
    ret = calc_memory(idx + 1, total_cost);

    //���� ���� ��Ȱ��ȭ ��Ű�� ���
    if (c[idx] <= total_cost)
        //���� ���� ��Ȱ��ȭ ��Ű�� ���� ���� ���Ͽ� �� ū �޸𸮸� ����
        ret = max(ret, m[idx] + calc_memory(idx + 1, total_cost - c[idx]));

    return cache[idx][total_cost] = ret;
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> m[i];
    for (int i = 1; i <= N; i++)
        cin >> c[i];

    //�޸������̼��� Ȱ���ϱ� ���� �ʱ�ȭ
    memset(cache, -1, sizeof(cache));

    int ret = 0;

    //������ �ִ� �ڽ�Ʈ�� 10000���� Ž���� �����ϵ��� ����.
    for (int i = 0; i < 10001; i++) {
        ret = calc_memory(1, i);
        if (ret >= M) {
            cout << i;
            break;
        }
    }

    return 0;
}

// Ʋ�� (�賶������ ������ ������...)