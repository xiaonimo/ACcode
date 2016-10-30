/* title
 * ��һ�����е��������ӽڵ������ӽڵ㣬�������ӽڵ������ӽڵ㡣

 * �����˼·�ܵ�maxDepth����˼·��Ӱ�죬ʹ��queue���У�����tree��ÿһ��ڵ㡣
 * ��һ�ֱȽϼ��ķ�����ʹ�õݹ顣
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

//swap������c++�����ú�����
treeNode* invertTree(treeNode* root) {
		if (!root) {
			return root;
		}
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}