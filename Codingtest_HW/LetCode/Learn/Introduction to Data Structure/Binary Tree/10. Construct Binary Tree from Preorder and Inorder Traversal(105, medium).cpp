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
    //

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (inorder.size() == 0) {
            return nullptr;
        }
        else if (inorder.size() == 1) {
            TreeNode* node = new TreeNode(inorder[0]);
            return node;
        }

        int rootValue = preorder[0];

        //��Ʈ�� inorder���� ã�� ���� ������ ����
        for (int i = 0; i < inorder.size(); i++) {
            if (rootValue == inorder[i]) {

                vector<int> new_inorder_left, new_inorder_right;

                for (int j = 0; j < i; j++) {
                    new_inorder_left.push_back(inorder[j]);
                }
                //0 ~ i-1 �� ����
                for (int j = i + 1; j < inorder.size(); j++) {
                    new_inorder_right.push_back(inorder[j]);
                }
                vector<int> new_preorder_left, new_preorder_right;

                for (int j = 1; j < new_inorder_left.size() + 1; j++) {
                    new_preorder_left.push_back(preorder[j]);
                }
                for (int j = new_inorder_left.size() + 1; j < preorder.size(); j++) {
                    new_preorder_right.push_back(preorder[j]);
                }


                TreeNode* pLeftRoot = buildTree(new_preorder_left, new_inorder_left);
                TreeNode* pRightRoot = buildTree(new_preorder_right, new_inorder_right);

                TreeNode* pRoot = new TreeNode(inorder[i]);
                pRoot->left = pLeftRoot;
                pRoot->right = pRightRoot;

                return pRoot;
            }
        }

        return nullptr;
    }
};