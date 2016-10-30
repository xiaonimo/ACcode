/* Given a binary tree and a sum, determine if the tree has a 
 * root-to-leaf path such that adding up all the values 
 * along the path equals the given sum.

 * For example:
 * Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */
#include <iostream>
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
	//DFS
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
			return false;
		if (!root->left && !root->right)
			return root->val == sum;
		else
			return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
	//loop
	bool hasPathSum1(TreeNode* root, int sum) {
		if (!root)
			return false;
		queue<TreeNode*> path;
		queue<int> val;
		path.push(root);
		val.push(root->val);
		while (path.empty()) {
			auto sz = path.size();
			for (decltype(sz) i = 0; i < sz; ++i) {
				TreeNode *tnode = path.front();
				int tval = val.front();
				path.pop();
				val.pop();
				if (!tnode->left && !tnode->right && (tval == sum))
					return true;
				if (tnode->left) {
					path.push(tnode->left);
					val.push(tval + tnode->left->val);
				}
				if (tnode->right) {
					path.push(tnode->right);
					val.push(tval + tnode->right->val);
				}
			}
		}
		return false;
	}
};

int main()
{
	Solution s = Solution();
	TreeNode *p1 = new TreeNode(1);
	s.hasPathSum1(p1, 1);
	system("pause");
	return 0;
}