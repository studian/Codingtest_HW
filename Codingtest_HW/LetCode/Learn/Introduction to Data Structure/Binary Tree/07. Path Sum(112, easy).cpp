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
    // 재귀로
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        targetSum -= root->val;

        // leaf 노드이면 -> targetsum = 0이면 제대로 타겟을 찾은거고 아니면 잘 못찾은것임
        if (root->left == NULL && root->right == NULL) return (targetSum == 0);

        // 모두 검색 후 결과를 알기 위해.
        return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));
    }

    // stack으로--> ??
    /*
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // leaf 노드이면 -> targetsum = 0이면 제대로 타겟을 찾은거고 아니면 잘 못찾은것임
        //if(root->left == NULL && root->right == NULL) return (targetSum==0);  

        stack<TreeNode*> s; // stack 만들고
        s.push(root); // root 넣고

        while (s.empty()) {
            TreeNode* current = s.top(); // 스텍에서 젤 위에꺼 꺼내고
            s.pop(); // 스텍에서 꺼낸 데이터 (젤 위에꺼) 삭제

            targetSum -= root->val;

            // leaf 노드이면 -> targetsum = 0이면 제대로 타겟을 찾은거고 아니면 잘 못찾은것임
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

        // 모두 검색 후 return true한게 없으면 값이 없는거.
        return false;
    }
    */
};