/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        queue<TreeNode*> q;

        if (!root)
        {
            return output;
        }

        q.push(root);

        while (!q.empty())
        {
            int q_size = q.size();

            vector<int> node;

            while (q_size--)
            {
                TreeNode* q_temp = q.front();
                node.push_back(q_temp->val);
                q.pop();

                if (q_temp->left)
                {
                    q.push(q_temp->left);
                }
                if (q_temp->right)
                {
                    q.push(q_temp->right);
                }
            }
            output.push_back(node);
        }
        return output;
    }
};