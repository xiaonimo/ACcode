/* Title:
 * Find the sum of all left leaves in a given binary tree.
 * Example:

    3
   / \
  9  20
    /  \
   15   7

 * There are two left leaves in the binary tree, 
 * with values 9 and 15 respectively. Return 24.
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
#include<cassert>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	//too complex
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root)
			return 0;
		int sum = 0;
		sumOf(root, root->left, sum);
		sumOf(root, root->right, sum);
		return sum;
	}
	void sumOf(TreeNode *parent, TreeNode *cur, int &sum) {
		if (!cur) return;
		if (!cur->left && !cur->right && cur == parent->left) {
			sum += cur->val;
			return;
		}
		if (cur->left)
			sumOf(cur, cur->left, sum);
		if (cur->right)
			sumOf(cur, cur->right, sum);
		return;
	}

	int sumOfLeftLeaves1(TreeNode *root) {
		if (!root) return 0;
		if (root->left && !root->left->left && !root->left->right)
			return root->left->val + sumOfLeftLeaves1(root->right);
		return sumOfLeftLeaves1(root->left) + sumOfLeftLeaves1(root->right);
	}
};

int main(void)
{
	
	system("pause");
	return 0;
}
