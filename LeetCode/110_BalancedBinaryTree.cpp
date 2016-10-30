/* Given a binary tree, determine if it is height-balanced.

 * For this problem, a height-balanced binary tree is defined as a binary tree 
 * in which the depth of the two subtrees of every node never differ by more than 1.
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
	//16ms,if it is a balances tree,two limits:
	//1.the difference of the left child tree and the right child tree's height 
	//is not more than 1;
	//2.tow child tree both are balances trees;
	//N*log(N)
	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
			return false;
		else
			return isBalanced(root->left) && isBalanced(root->right);
	}
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		return (max(maxDepth(root->left), maxDepth(root->right))) + 1;
	}
	//o(N)
	int height(TreeNode *root)
	{
		if (root == NULL) 
			return 0;
		int hl = height(root->left);
		int hr = height(root->right);
		if (hl == -1 || hr == -1 || abs(hl - hr) > 1) 
			return -1;
		return max(hl, hr) + 1;
	}
	bool isBalanced(TreeNode *root) {
		return height(root) != -1;
	}
};

int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}