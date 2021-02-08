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

        //level이랑 level별 노드들 담을 맵
        map<int, vector<int>> maps;

        //bfs용
        queue<pair<TreeNode*, int> > que;

        if (root == NULL) return result;



        //첫번째 레벨 맵에 추가
        vector<int> temp;
        que.push({ root, 1 });
        temp.push_back(root->val);
        maps[1] = temp;


        //bfs시작 
        while (!que.empty()) {

            pair<TreeNode*, int> ft = que.front();
            que.pop();

            //해당 레벨에 노드값들 담을 용도로 벡터 생성
            vector<int> t;

            //꺼낸 노드의 왼쪽 자식  넣기 
            if (ft.first->left) {
                que.push({ ft.first->left, ft.second + 1 });
                t.push_back(ft.first->left->val);
            }
            //꺼낸 노드의 오른쪽 자식 넣기
            if (ft.first->right) {
                que.push({ ft.first->right, ft.second + 1 });
                t.push_back(ft.first->right->val);
            }

            //이미 maps에  해당 자식 레벨값이 존재하면..   t벡터안에 들어있는값들 map에 넣어주고
            if (maps.find(ft.second + 1) != maps.end()) {
                for (auto node : t) {
                    maps[ft.second + 1].push_back(node);
                }
            }
            //maps에 해당 자식 레벨값이 존재하지않았다면  최초로 값들 넣어주고
            else {
                if (t.size() != 0)
                    maps.insert({ ft.second + 1, t });

                // map[ft->second+1].in = t;

            }
        }

        //map이 key값기준 오름차순 정렬되있다보니 차례대로 반복문 돌리면서
        //결과 배열에 담음 
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