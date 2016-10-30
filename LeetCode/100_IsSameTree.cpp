/* Write a function to delete a node (except the tail) in a singly linked list, 
 * given only access to that node.

 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node 
 * with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 */
#include <iostream>
#include <string>
#include <vector>
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
	//0ms
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!q&&p || q&&!p) {
			return false;
		}
		else if (!p && !q) {
			return true;
		}
		else if (p->val == q->val) {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		else {
			return false;
		}
	}
	//Same way,but very neat.
	bool isSameTree1(TreeNode *p, TreeNode *q) {
		if (!p || !q) {
			return p == q;
		}
		else {
			return (p->val == q->val) && isSameTree(p->left, q->left)
				&& (p->right, q->right);
		}
	}
};

int main()
{
	Solution s = Solution();

	system("pause");
	return 0;
}