/* Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest 
 * path from the root node down to the nearest leaf node.
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
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
	//DFS, 12ms.
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		else if (root->left && root->right)
			return min(minDepth(root->left), minDepth(root->right)) + 1;
		else if (root->left && !root->right)
			return minDepth(root->left) + 1;
		else
			return minDepth(root->right) + 1;
	}
	//BFS
	int minDepth1(TreeNode *root) {
		if (!root)
			return 0;
		int dep = 1;
		queue<TreeNode*> nodes;
		nodes.push(root);
		while (!nodes.empty()) {
			auto sz = nodes.size();
			for (decltype(sz) i = 0; i < sz; ++i) {
				TreeNode *tnode = nodes.front();
				nodes.pop();
				if (!tnode->left && !tnode->right)
					return dep;
				if (tnode->left)
					nodes.push(tnode->left);
				if (tnode->right)
					nodes.push(tnode->right);
			}
			++dep;
		}
	}
};

int main()
{
	Solution s = Solution();

	system("pause");
	return 0;
}