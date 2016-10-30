/* Given a binary tree, return all root-to-leaf paths.
 * For example, given the following binary tree:
	   1
	 /   \
	2     3
	 \
	  5
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
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
	//DFS,4ms, good
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res{};
		string path{};
		if (!root)
			return res;
		process(res, path, root);
		return res;
	}
	//every recursion level will store a temp path. 
	void process(vector<string> &res, string path, TreeNode *root) {
		path += to_string(root->val);
		if (!root->left && !root->right) {
			res.push_back(path);
			return;
		}
		if (root->right) {
			process(res, path + string("->"), root->right);
		}
		if (root->left) {
			process(res, path + string("->"), root->left);
		}
	}

	vector<string> binaryTreePaths1(TreeNode* root) {
		vector<string> res{};
		if (!root)
			return res;
		queue<TreeNode*> nodes;
		queue<string> paths;
		nodes.push(root);
		paths.push(to_string(root->val));
		while (!nodes.empty()) {
			auto sz = nodes.size();
			for (decltype(sz) i = 0; i < sz; ++i) {
				TreeNode * tnode = nodes.front();
				string tpath = paths.front();
				nodes.pop();
				paths.pop();
				if (!tnode->left && !tnode->right) {
					res.push_back(tpath);
					continue;
				}
				if (tnode->left) {
					nodes.push(tnode->left);
					paths.push(tpath + string("->") + to_string(tnode->left->val));
				}
				if (tnode->right) {
					nodes.push(tnode->right);
					paths.push(tpath + string("->") + to_string(tnode->right->val));
				}
			}
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