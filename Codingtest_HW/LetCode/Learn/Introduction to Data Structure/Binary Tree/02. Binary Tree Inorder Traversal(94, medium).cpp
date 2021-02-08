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
    /*vector<int> inorderTraversal(TreeNode* root) {

    }*/

    // method 1: stack --?? 모르겠음
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return {};

        vector<int> output;
        stack<TreeNode*> stact_tree;
        stact_tree.push(root);

        while (!stact_tree.empty()) {
            // remove and print current node from stack 
            // stack 으로 부터 현재 노드 제거 후 출력
            TreeNode* curr = stact_tree.top();
            stact_tree.pop();
            
            // inorder: left->root->right
            // left -> right 순서로 출력(삭제) 되려면 => right -> left 순서로 입력해야 함
            if (curr->right)
                stact_tree.push(curr->right);

            output.push_back(curr->val);

            if (curr->left)
                stact_tree.push(curr->left);
        }

        return output;
    }

    // method 2: recursive
    vector<int> output;
    vector<int> inorderTraversal(TreeNode* root) {

        if (root) {
            inorderTraversal(root->left);
            output.push_back(root->val);            
            inorderTraversal(root->right);
        }
        return output;
    }

    // method 3: recursive
    void inorder(TreeNode* node, vector<int>& output) {
        if (node == nullptr) { return; }

        inorder(node->left, output);
        output.push_back(node->val);
        inorder(node->right, output);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        inorder(root, output);
        return output;
    }
};