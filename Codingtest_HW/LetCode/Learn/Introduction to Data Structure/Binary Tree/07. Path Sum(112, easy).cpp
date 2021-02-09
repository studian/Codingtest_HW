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

        // 루트가 leaf 노드일때 val == targetsum이면 제대로 타겟을 찾은거고 아니면 잘 못찾은것임
        //if (root->left == NULL && root->right == NULL) return (root->val == targetSum);

        //At each node we will store the value sum of previous nodes
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* current = s.top(); // 스텍에서 젤 위에꺼 꺼내고
            s.pop(); // 스텍에서 꺼낸 데이터 (젤 위에꺼) 삭제

            // leaf 노드일때 현재 val == targetsum이면 제대로 타겟을 찾은거고 아니면 잘 못찾은것임
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