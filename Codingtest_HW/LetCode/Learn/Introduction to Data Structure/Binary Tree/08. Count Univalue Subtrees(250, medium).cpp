class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {

        int ans = 0;

        dfs(root, ans);

        return ans;
    }

    void dfs(TreeNode* root, int& ans)
    {
        if (!root) return;

        if (subTree(root->left, root->val) && subTree(root->right, root->val)) ans++;

        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    bool subTree(TreeNode* root, int val)
    {
        if (!root) return true;

        if (root->val != val) return false;

        return subTree(root->left, root->val) && subTree(root->right, root->val);
    }
};