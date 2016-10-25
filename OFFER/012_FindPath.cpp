/* Title:
 * 输入一颗二叉树和一个整数，
 * 打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点
 * 所经过的结点形成一条路径。
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> trace;
        FindPath(root, expectNumber, res, trace);
        return res;
    }
    void FindPath(TreeNode* root, int expectNumber,
                  vector<vector<int>> &res, vector<int> trace) {
        trace.push_back(root->val);
        if (!root->left && !root->right && expectNumber == root->val) {
            res.push_back(trace);
            return;
        }
        if (root->left)
            FindPath(root->left,expectNumber-root->val,res,trace);
        if (root->right)
            FindPath(root->right,expectNumber-root->val,res,trace);
    }
};

int main() {


}
