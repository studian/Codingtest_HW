/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;

        //level�̶� level�� ���� ���� ��
        map<int, vector<int>> maps;

        //bfs��
        queue<pair<TreeNode*, int> > que;

        if (root == NULL) return result;



        //ù��° ���� �ʿ� �߰�
        vector<int> temp;
        que.push({ root, 1 });
        temp.push_back(root->val);
        maps[1] = temp;


        //bfs���� 
        while (!que.empty()) {

            pair<TreeNode*, int> ft = que.front();
            que.pop();

            //�ش� ������ ��尪�� ���� �뵵�� ���� ����
            vector<int> t;

            //���� ����� ���� �ڽ�  �ֱ� 
            if (ft.first->left) {
                que.push({ ft.first->left, ft.second + 1 });
                t.push_back(ft.first->left->val);
            }
            //���� ����� ������ �ڽ� �ֱ�
            if (ft.first->right) {
                que.push({ ft.first->right, ft.second + 1 });
                t.push_back(ft.first->right->val);
            }

            //�̹� maps��  �ش� �ڽ� �������� �����ϸ�..   t���;ȿ� ����ִ°��� map�� �־��ְ�
            if (maps.find(ft.second + 1) != maps.end()) {
                for (auto node : t) {
                    maps[ft.second + 1].push_back(node);
                }
            }
            //maps�� �ش� �ڽ� �������� ���������ʾҴٸ�  ���ʷ� ���� �־��ְ�
            else {
                if (t.size() != 0)
                    maps.insert({ ft.second + 1, t });

                // map[ft->second+1].in = t;

            }
        }

        //map�� key������ �������� ���ĵ��ִٺ��� ���ʴ�� �ݺ��� �����鼭
        //��� �迭�� ���� 
        for (map<int, vector<int>>::iterator iter = maps.begin(); iter != maps.end(); iter++) {
            vector<int> temp;

            for (auto i : iter->second) {
                temp.push_back(i);
            }
            result.push_back(temp);
        }


        return result;
    }
};