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
    // ��ͷ�
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        targetSum -= root->val;

        // leaf ����̸� -> targetsum = 0�̸� ����� Ÿ���� ã���Ű� �ƴϸ� �� ��ã������
        if (root->left == NULL && root->right == NULL) return (targetSum == 0);

        // ��� �˻� �� ����� �˱� ����.
        return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));
    }

    // stack����--> ??
    bool hasPathSum(TreeNode* root, int targetSum) {
        //Base condition
        if (!root) return false;

        //If tree contains only single node
        if (root->left == NULL && root->right == NULL) return (root->val == targetSum);

        //At each node we will store the value sum of previous nodes
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* temp = stk.top();
            stk.pop();

            //To check it node is leaf node and sum equals target Sum
            if (temp->left == NULL && temp->right == NULL && temp->val == targetSum)return true;

            else
                if (temp->right) {
                    //Add value to next node and push on stack
                    temp->right->val += temp->val;
                    stk.push(temp->right);
                }
            if (temp->left) {
                //Add value to next node and push on stack
                temp->left->val += temp->val;
                stk.push(temp->left);
            }``
        }
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        //Base condition
        if (!root) return false;

        // ��Ʈ�� leaf ����϶� val == targetsum�̸� ����� Ÿ���� ã���Ű� �ƴϸ� �� ��ã������
        //if (root->left == NULL && root->right == NULL) return (root->val == targetSum);

        //At each node we will store the value sum of previous nodes
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* current = s.top(); // ���ؿ��� �� ������ ������
            s.pop(); // ���ؿ��� ���� ������ (�� ������) ����

            // leaf ����϶� ���� val == targetsum�̸� ����� Ÿ���� ã���Ű� �ƴϸ� �� ��ã������
            if (current->left == NULL && current->right == NULL && current->val == targetSum) {
                //return (current->val == targetSum);
                return true;
            }
            else {
                if (current->right) {
                    //Add value to next node and push on stack
                    current->right->val += current->val;
                    s.push(current->right);
                }

                if (current->left) {
                    //Add value to next node and push on stack
                    current->left->val += current->val;
                    s.push(current->left);
                }
            }
        }
        return false;
    }
};