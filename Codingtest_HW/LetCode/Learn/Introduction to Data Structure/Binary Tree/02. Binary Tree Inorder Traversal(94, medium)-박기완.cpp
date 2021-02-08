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

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;

        TreeNode* temp = root;

        for (; temp != NULL; temp = temp->left) {
            stk.push(temp);
        }

        while (stk.empty() == 0) {
            TreeNode* tp = stk.top();
            result.push_back(tp->val);
            stk.pop();

            if (tp->right) {
                temp = tp->right;

                for (; temp != NULL; temp = temp->left) {
                    stk.push(temp);
                }

            }
        }






        return result;
    }
};