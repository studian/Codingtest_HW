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

#include <stack>
#include <set>

using namespace std;

//방문여부용도로  set을 쓸게요 



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> resultList;
        set<TreeNode*> visit;
        stack<TreeNode*> stk;

        if (root == NULL) {
            return resultList;
        }

        //루트 방문처리
        visit.insert(root);
        resultList.push_back(root->val);
        stk.push(root);


        while (!stk.empty()) {
            bool isPop = false;
            TreeNode* tp = stk.top();
            if (tp == NULL) {
                stk.pop();
                continue;
            }
            //왼쪽 노드가 존재하고 방문한적이 없다면
            if (tp->left && visit.find(tp->left) == visit.end()) {
                //방문처리하고
                visit.insert(tp->left);
                //스택에 넣고
                stk.push(tp->left);
                //출력하고
                resultList.push_back(tp->left->val);
                isPop = true;
                continue;
            }
            //오른쪽 노드가 존재하고 방문한적이 없다면
            if (tp->right && visit.find(tp->right) == visit.end()) {
                //방문처리하고
                visit.insert(tp->right);
                //스택에 넣고
                stk.push(tp->right);
                //출력하고
                resultList.push_back(tp->right->val);
                isPop = true;
            }

            if (isPop == false) {
                stk.pop();
            }



        }

        return resultList;
    }
};