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

// DFS+Àç±Í
class Solution {
public:
	void dfsHelper(Node* root, Node* parent) {
		if (!root)
			return;

		if (parent && parent->right) {
			if (parent->right != root) {
				root->next = parent->right;
			}
			else if (parent->next) {
				root->next = parent->next->left;
			}
		}
		dfsHelper(root->left, root);
		dfsHelper(root->right, root);
	}

	Node* connect(Node* root) {
		if (!root)
			return nullptr;
		dfsHelper(root, nullptr);
	}
};