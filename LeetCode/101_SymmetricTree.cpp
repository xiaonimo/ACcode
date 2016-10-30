/* Given a binary tree, check whether it is a mirror of itself 
 * (ie, symmetric around its center).

 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
		1
	   / \
	  2   2
	 / \ / \
	3  4 4  3
 * But the following [1,2,2,null,3,null,3] is not:
		1
	   / \
	  2   2
	   \   \
	   3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	//4ms,recursive,DFS
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return isSy(root->left, root->right);
	}
	bool isSy(TreeNode* l, TreeNode* r) {
		if (!l&&r || l&&!r)
			return false;
		else if (!l && !r)
			return true;
		else if (l->val == r->val)
			return isSy(l->left, r->right) && isSy(l->right, r->left);
		else
			return false;
	}
	//BFS,use two queue to store the tree
	bool isSymmetric0(TreeNode* root) {
		if (!root)
			return true;
		queue<TreeNode*> lque, rque;
		lque.push(root->left );
		rque.push(root->right);
		while (!lque.empty() && !rque.empty()) {
			TreeNode *lnode = lque.front();
			TreeNode *rnode = rque.front();
			lque.pop();
			rque.pop();
			if (!lnode && !rnode)
				continue;
			if (!lnode &&rnode || !rnode&&lnode)
				return false;
			if (lnode->val != rnode->val)
				return false;
			lque.push(lnode->left);
			lque.push(lnode->right);
			rque.push(rnode->right);
			rque.push(rnode->left);
		}
		return true;
	}
	//BFS,use stack and queue,but lt's not accepted,l don't know why?
	bool isSymmetric1(TreeNode* root) {
		if (!root )
			return true;
		queue<TreeNode*> node_que;
		node_que.push(root->left );
		node_que.push(root->right);
		while (!node_que.empty()) {
			stack<int> level_val;
			unsigned int level_size = node_que.size();
			for (unsigned int i = 0; i < level_size; ++i) {
				int cur_val = 0;
				TreeNode *cur = node_que.front();
				node_que.pop();
				
				cur_val = !cur ? 0 : cur->val;
				if (level_val.empty() || level_val.top() != cur_val)
					level_val.push(cur_val);
				else
					level_val.pop();

				if (cur && cur->left)
					node_que.push(cur->left );
				if (cur && cur->right)
					node_que.push(cur->right);
			}
			if (!level_val.empty())
				return false;
		}
		return true;
	}

};

int main()
{
	Solution s = Solution();
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(2);
	TreeNode *p4 = new TreeNode(3);
	TreeNode *p5 = new TreeNode(4);
	TreeNode *p6 = new TreeNode(4);
	TreeNode *p7 = new TreeNode(3);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p3->left = p6;
	p3->right = p7;
	
	cout << (s.isSymmetric0(p1) ? "true" : "false");
	system("pause");
	return 0;
}