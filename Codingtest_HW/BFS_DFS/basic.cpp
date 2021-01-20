//8 8
//1 3
//3 5
//5 2
//2 8
//7 8
//4 7
//4 6
//1 4


//8 8
//1 3
//3 5
//5 2
//2 8
//7 8
//4 6
//4 7
//1 4

#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

// list+stak dfs
// bfs: arr / list/ arr+ť / list+ť

using namespace std;

int N, B; // ����, ����
int arr[9][9] = { 0, }; // ������� ����
int v_arr[9] = { 0, }; // ������� ����
vector< vector <int> > arrLst(9); // ��������Ʈ ���� vector <int> a[n+1];


void DFS_arr(int start_node_idx)
{	
	cout << start_node_idx << "\n";
	if (v_arr[start_node_idx] == 1) return;
	v_arr[start_node_idx] = 1;

	for (int j = 1; j <= N; j++) {
		if (arr[start_node_idx][j] == 1 && v_arr[j] == 0)
		{
			DFS_arr(j);
		}
	}	
}

void DFS_arr_Stack(int start_node_idx)
{
	stack <int> s_dfs;

	cout << start_node_idx << "\n";
	s_dfs.push(start_node_idx);
	v_arr[start_node_idx] = 1;

	while (!s_dfs.empty())
	{
		int top = s_dfs.top();

		// ���� for ����Ǵ��� Ȯ��, 
		// ���� �ȵǸ�(top_check>0) �ش� top�� ��忡 ����� ������ 
		// ��� �湮ó����ٴ� �ǹ̴� �����ϸ��
		int top_check = 0; 

		for (int j = 1; j <= N; j++)
		{
			if (arr[top][j] == 1 && v_arr[j] == 0)
			{
				top_check++;
				cout << j << "\n";
				s_dfs.push(j);
				v_arr[j] = 1;
				break;
			}
		}

		if (top_check == 0)
			s_dfs.pop();
	}
}

void DFS_list(int start_node_idx)
{
	cout << start_node_idx << "\n";
	if (v_arr[start_node_idx] == 1) return;
	v_arr[start_node_idx] = 1;

	for (auto& i : arrLst[start_node_idx])
	{
		if (v_arr[i] == 0)
		{
			DFS_list(i);
		}		
	}
}

void DFS_list_Stack(int start_node_idx)
{
	stack <int> s_dfs2;

	cout << start_node_idx << "\n";
	s_dfs2.push(start_node_idx);
	v_arr[start_node_idx] = 1;

	while (!s_dfs2.empty())
	{
		int top = s_dfs2.top();

		// ���� for ����Ǵ��� Ȯ��, 
		// ���� �ȵǸ�(top_check>0) �ش� top�� ��忡 ����� ������ 
		// ��� �湮ó����ٴ� �ǹ̴� �����ϸ��
		int top_check = 0;

		for (auto& i : arrLst[top])
		{
			if (v_arr[i] == 0)
			{
				top_check++;
				cout << i << "\n";
				s_dfs2.push(i);
				v_arr[i] = 1;
				break;
			}
		}

		if (top_check == 0)
			s_dfs2.pop();
	}
}

int main()
{
	cin >> N >> B;

	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1; // ����Ǹ� 1, �ȵǸ� 0
		arr[b][a] = 1; // ����Ǹ� 1, �ȵǸ� 0
		arrLst[a].push_back(b);
		arrLst[b].push_back(a);
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 1; i <= N; i++) {
		cout << "Node Num [" << i << "] : ";
		for (auto& i : arrLst[i]) {
			cout << i << " ";
		}
		cout << endl;
	}*/

	cout << "DFS_arr \n";
	DFS_arr(3);

	memset(v_arr, 0, sizeof(v_arr));
	cout << "DFS_list \n";	
	DFS_list(3);

	memset(v_arr, 0, sizeof(v_arr));
	cout << "DFS_arr_stack \n";
	DFS_arr_Stack(3);

	memset(v_arr, 0, sizeof(v_arr));
	cout << "DFS_list_Stack \n";
	DFS_list_Stack(3);
}