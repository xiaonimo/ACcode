/* title
 * 把一棵树中的所有左子节点变成右子节点，所有右子节点变成左子节点。

 * 这题的思路受到maxDepth解题思路的影响，使用queue队列，处理tree的每一层节点。
 * 另一种比较简便的方法是使用递归。
 */

class solution {
public:
	treeNode* invertTree(treeNode* root) {
		if (!root) {
			return root;
		}
		queue<treeNode*> s;
		s.push(root);
		while (!s.empty()) {
			for (int i = 0, n = s.size(); i < n; ++i) {
				treeNode *p = s.front();
				if (p->left || p->right) {
					treeNode *tmp = p->left;
					p->left = p->right;
					p->right = tmp;
				}
				if (p->left) {
					s.push(p->left);
				}
				if (p->right) {
					s.push(p->right);
				}
				s.pop();
			}
			
		}
		return root;
	}
};

//swap函数是c++的内置函数。
treeNode* invertTree(treeNode* root) {
		if (!root) {
			return root;
		}
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}