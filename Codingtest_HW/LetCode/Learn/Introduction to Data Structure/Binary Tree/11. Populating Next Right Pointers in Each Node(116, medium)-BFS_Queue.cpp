/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


#include <queue>
using namespace std;



class Solution {
public:
    // Approach 1: Level Order Traversal
    // T = O(n) & S = O(n) where n is total number of nodes
    Node* connect(Node* root) {
        if (!root)return root;
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int n = Q.size();
            for (int i = 0; i < n; i++) {
                Node* x = Q.front();
                Q.pop();
                if (i != n - 1)x->next = q.front();
                if (x->left)Q.push(x->left);
                if (x->right)Q.push(x->right);
            }
        }
        return root;
    }

    // Approach 2: Using previously established next pointers
    // node.left.next = node.right
    // node.right.next = node.next.left

    // 재귀
    Node* connect(Node* root) {
        if (root) {
            if (root->left) {
                root->left->next = root->right;

                if (root->next) {
                    root->right->next = root->next->left;
                }

                connect(root->left);
                connect(root->right);
            }
        }
        return root;
    }

    // 포인터
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node* curr = root, * next = NULL;

        while (curr && curr->left) {
            // next 가 NULL이면 새 계층의 시작
            if (next == NULL) next = curr->left;
            curr->left->next = curr->right;

            // 현재(curr)에 다음(next) 노드가 없으면 현재 계층의 끝임
            if (curr->next == NULL) {
                // 현재 노드를 다음 노드로 설정
                curr = next;
                // 다음 루프 턴에서 새 계층의 시작임을 알리기 위해
                next = NULL;
            }
            else {
                curr->right->next = curr->next->left;
                curr = curr->next;
            }
        }
        return root;
    }

    
};