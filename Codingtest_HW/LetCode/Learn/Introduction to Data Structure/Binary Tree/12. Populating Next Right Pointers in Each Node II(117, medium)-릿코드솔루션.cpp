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

class Solution {
public:
    // C++ DFS solution
    map<int, list<Node*>> m;
    Node* connect(Node* root) {

        DFS(root, 0);

        for (auto i : m)
        {
            list<Node*> l = i.second;
            Node* temp = *(l.begin());
            for (auto k = ++l.begin(); k != l.end(); k++)
            {
                temp->next = *k;
                temp = *k;
            }
        }
        return root;

    }
    void DFS(Node* root, int height)
    {
        if (root == NULL) return;

        m[height].push_back(root);
        DFS(root->left, height + 1);
        DFS(root->right, height + 1);
    }

    // Keep track of the previous node prev in the next level. 
    // Once the current level is completely traversed, change curr to next, which is the first node in the next level.
    Node* connect(Node* root) {
        Node* first = root;
        while (first) {
            Node* curr = first, * next = 0, * prev = 0;
            while (curr) {
                if (curr->left) {
                    if (prev)
                        prev->next = curr->left, prev = curr->left;
                    else
                        next = prev = curr->left;
                }
                if (curr->right) {
                    if (prev)
                        prev->next = curr->right, prev = curr->right;
                    else
                        next = prev = curr->right;
                }
                curr = curr->next;
            }
            first = next;
        }
        return root;
    }
};