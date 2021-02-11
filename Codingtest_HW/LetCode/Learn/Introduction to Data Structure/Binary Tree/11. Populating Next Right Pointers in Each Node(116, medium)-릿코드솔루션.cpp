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

// BFS+ť
class Solution {
public:
	Node* connect(Node* root) {
		queue<pair<Node*, int>>qt; // ���, ������

		Node* ans = root;

		if (root) {
			qt.push({ root,0 }); // ���, ������
		}

		while (!empty(qt)) {
			Node* t = qt.front().first; // ���
			int level = qt.front().second; //������
			qt.pop();
			if (!qt.empty() and lvl == qt.front().second) {
				t->next = qt.front().first;
			}
			if (t->left) {
				qt.push({ t->left, level + 1 });
			}
			if (t->right) {
				qt.push({ t->right, level + 1 });
			}
		}
		return ans;
	}
};