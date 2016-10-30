/* Given a binary tree, return the level order traversal of its nodes' values. 
 * (ie, from left to right, level by level).

 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
		3
	   / \
	  9  20
		/  \
	   15   7
 * return its level order traversal as:
	[
	  [3],
	  [9,20],
	  [15,7]
	]
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
	//DFS,8ms.
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		process(res, 0, root);
		return res;
	}
	void process(vector<vector<int>> &res, int dep, TreeNode *node) {
		if (!node)
			return;
		if (res.size() <= dep) 
			res.push_back({});
		res[dep].push_back(node->val);
		if (node->left)
			process(res, dep + 1, node->left);
		if (node->right)
			process(res, dep + 1, node->right);
	}
	//BFS,8ms
	vector<vector<int>> levelOrder1(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode*> level_node;
		level_node.push(root);
		while (!level_node.empty()) {
			vector<int> level_val;
			auto sz = level_node.size();
			for (decltype(sz) i = 0; i < sz; ++i) {
				TreeNode *node = level_node.front();
				level_node.pop();
				level_val.push_back(node->val);
				if (node->left)
					level_node.push(node->left);
				if (node->right)
					level_node.push(node->right);
			}
			res.push_back(level_val);
		}
		return res;
	}
};

int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}