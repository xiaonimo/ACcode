/* Given a binary tree, return the bottom-up level order traversal 
 * of its nodes' values. (ie, from left to right, level by level from leaf to root).

 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
		3
	   / \
	  9  20
		/  \
	   15   7
 * return its bottom-up level order traversal as:
	[
	  [15,7],
	  [9,20],
	  [3]
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
	//8ms,BFS
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) {
			return res;
		}
		queue<TreeNode*> t;
		t.push(root);
		while (!t.empty()) {
			vector<int> tn;
			int cnt = t.size();
			for (unsigned int i = 0; i < cnt; ++i) {
				TreeNode *cur = t.front();
				tn.push_back(cur->val);
				t.pop();
				if (cur->left)
					t.push(cur->left);
				if (cur->right)
					t.push(cur->right);
			}
			//do not use insert() here,it cost too much time.
			//use reverse() insteadly
			res.push_back(tn);
		}
		reverse(res.begin(), res.end());
		return res;
	}
	//8ms,DFS
	vector<vector<int>> levelOrderBottom1(TreeNode* root) {
		vector<vector<int>> res;
		levelOrder(res, root, 0);
		reverse(begin(res), end(res));
		return res;
	}
	void levelOrder(vector<vector<int>> &vec, TreeNode* root, unsigned int dep) {
		if (!root)
			return;
		if (dep >= vec.size())
			vec.push_back({});
		vec[dep].push_back(root->val);
		levelOrder(vec, root->left,  dep + 1);
		levelOrder(vec, root->right, dep + 1);
	}
};

int main()
{
	Solution s = Solution();
	TreeNode *p1 = new TreeNode(3);
	TreeNode *p2 = new TreeNode(9);
	TreeNode *p3 = new TreeNode(20);
	TreeNode *p4 = new TreeNode(15);
	TreeNode *p5 = new TreeNode(7);
	TreeNode *p6 = new TreeNode(11);
	p1->left = p2;
	p1->right = p3;
	p3->left = p4;
	p3->right = p5;
	p2->left = p6;

	vector<vector<int>> a = s.levelOrderBottom1(p1);
	for (auto i : a) {
		for (auto b : i) {
			cout << b << '\t';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}