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
    /*
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // leaf ����̸� -> targetsum = 0�̸� ����� Ÿ���� ã���Ű� �ƴϸ� �� ��ã������
        //if(root->left == NULL && root->right == NULL) return (targetSum==0);  

        stack<TreeNode*> s; // stack �����
        s.push(root); // root �ְ�

        while (s.empty()) {
            TreeNode* current = s.top(); // ���ؿ��� �� ������ ������
            s.pop(); // ���ؿ��� ���� ������ (�� ������) ����

            targetSum -= root->val;

            // leaf ����̸� -> targetsum = 0�̸� ����� Ÿ���� ã���Ű� �ƴϸ� �� ��ã������
            if (current->left == NULL && current->right == NULL) return (targetSum == 0);
            else {
                if (current->right) {
                    s.push(current->right);
                }

                if (current->left) {
                    s.push(current->left);
                }
            }
        }

        // ��� �˻� �� return true�Ѱ� ������ ���� ���°�.
        return false;
    }
    */
};