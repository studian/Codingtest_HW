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

#include <stack>
#include <set>

using namespace std;

//�湮���ο뵵��  set�� ���Կ� 



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> resultList;
        set<TreeNode*> visit;
        stack<TreeNode*> stk;

        if (root == NULL) {
            return resultList;
        }

        //��Ʈ �湮ó��
        visit.insert(root);
        resultList.push_back(root->val);
        stk.push(root);


        while (!stk.empty()) {
            bool isPop = false;
            TreeNode* tp = stk.top();
            if (tp == NULL) {
                stk.pop();
                continue;
            }
            //���� ��尡 �����ϰ� �湮������ ���ٸ�
            if (tp->left && visit.find(tp->left) == visit.end()) {
                //�湮ó���ϰ�
                visit.insert(tp->left);
                //���ÿ� �ְ�
                stk.push(tp->left);
                //����ϰ�
                resultList.push_back(tp->left->val);
                isPop = true;
                continue;
            }
            //������ ��尡 �����ϰ� �湮������ ���ٸ�
            if (tp->right && visit.find(tp->right) == visit.end()) {
                //�湮ó���ϰ�
                visit.insert(tp->right);
                //���ÿ� �ְ�
                stk.push(tp->right);
                //����ϰ�
                resultList.push_back(tp->right->val);
                isPop = true;
            }

            if (isPop == false) {
                stk.pop();
            }



        }

        return resultList;
    }
};