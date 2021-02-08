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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

    }

    // method 2: recursive
    vector<int> output;
    vector<int> postorderTraversal(TreeNode* root) {

        if (root) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            output.push_back(root->val);
        }
        return output;
    }

    // method 3: recursive
    void postorder(TreeNode* node, vector<int>& output) {
        if (node == nullptr) { return; }

        // left -> right -> root
        postorder(node->left, output);        
        postorder(node->right, output);
        output.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        postorder(root, output);
        return output;
    }
};