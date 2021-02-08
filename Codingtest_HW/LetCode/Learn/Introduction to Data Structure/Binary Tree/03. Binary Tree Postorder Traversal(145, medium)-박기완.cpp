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

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        set<TreeNode*> visit;

        if (root == NULL) return result;

        stk.push(root);

        while (!stk.empty()) {

            TreeNode* tp = stk.top();
            bool isAllVisit = true;

            //tp-right가 존재하고 방문한적이 없다면
            if (tp->right && visit.find(tp->right) == visit.end()) {
                stk.push(tp->right);
                visit.insert(tp->right);
                isAllVisit = false;
            }

            //tp->left가 존재하고 방문한적 없다면
            if (tp->left && visit.find(tp->left) == visit.end()) {
                stk.push(tp->left);
                visit.insert(tp->left);
                isAllVisit = false;
            }




            if (isAllVisit) {
                result.push_back(tp->val);
                stk.pop();
            }

        }

        return result;
    }
};