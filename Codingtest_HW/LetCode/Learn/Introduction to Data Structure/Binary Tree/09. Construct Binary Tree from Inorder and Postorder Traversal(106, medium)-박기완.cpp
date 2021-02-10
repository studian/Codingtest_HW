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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if (inorder.size() == 0) {
            return nullptr;
        }
        else if (inorder.size() == 1) {
            TreeNode* node = new TreeNode(inorder[0]);
            return node;
        }

        int rootValue = postorder[postorder.size() - 1];

        //루트를 inorder에서 찾아 왼쪽 오른쪽 찢기
        for (int i = 0; i < inorder.size(); i++) {
            if (rootValue == inorder[i]) {

                vector<int> new_inorder_left, new_inorder_right;

                for (int j = 0; j < i; j++) {
                    new_inorder_left.push_back(inorder[j]);
                }
                //0 ~ i-1 가 왼쪽
                for (int j = i + 1; j < inorder.size(); j++) {
                    new_inorder_right.push_back(inorder[j]);
                }
                vector<int> new_postorder_left, new_postorder_right;

                for (int j = 0; j < postorder.size() - new_inorder_right.size() - 1; j++) {
                    new_postorder_left.push_back(postorder[j]);
                }
                for (int j = postorder.size() - new_inorder_right.size() - 1; j < postorder.size() - 1; j++) {
                    new_postorder_right.push_back(postorder[j]);
                }


                TreeNode* pLeftRoot = buildTree(new_inorder_left, new_postorder_left);
                TreeNode* pRightRoot = buildTree(new_inorder_right, new_postorder_right);

                TreeNode* pRoot = new TreeNode(inorder[i]);
                pRoot->left = pLeftRoot;
                pRoot->right = pRightRoot;

                return pRoot;
            }
        }

        return nullptr;
    }
};