/*Title
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two 
 * given nodes in the BST.

 * According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is 
 * defined between two nodes v and w as the lowest node in T that has both v and w 
 * as descendants (where we allow a node to be a descendant of itself).¡±

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. 
 * Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant 
 * of itself according to the LCA definition.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
}root(6), p1(2), p3(8), p4(0), p5(4), p6(7), p7(9), p8(3), p9(5);

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int big   = (p->val > q->val ? p->val : q->val);
		int small = (p->val < q->val ? p->val : q->val);
		/*if (big > root->val && small <= root->val) {
			return root;
		}
		else if (big < root->val) {
			return lowestCommonAncestor(root->left, p, q);
		}
		else {
			return lowestCommonAncestor(root->right, p, q);
		}*/
		
		while (true) {
			if (big > root->val && small <= root->val) {
				return root;
			}
			else if (big < root->val) {
				root = root->left;
			}
			else {
				root = root->right;
			}
		}

	}
};
int main()
{
	Solution s = Solution();
	root.left = &p1;
	root.right = &p3;
	p1.left = &p4;
	p1.right = &p5;
	p3.left = &p6;
	p3.right = &p7;
	p5.left = &p8;
	p5.right = &p9;
	cout << (s.lowestCommonAncestor(&root, &p4, &p5))->val;
	system("pause");
	return 0;
}