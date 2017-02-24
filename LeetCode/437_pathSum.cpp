#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //计算所有左叶子节点的和
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return _dfs(nullptr, root);
    }
    int _dfs(TreeNode* parent, TreeNode* child) {
        if (!child) return 0;
        if (!parent)
            return _dfs(child, child->left) + _dfs(child, child->right);
        return ((!child->right && !child->left && (parent->left == child))?child->val:0)
         + _dfs(child, child->left) + _dfs(child, child->right);
    }
};

//计算所有路径和为sum的路径条数
class Solution1 {
public:
    int pathSum(TreeNode* root, int sum) {
        return !root?0:_dfs(sum, root) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int _dfs(int sum, TreeNode *root) {
        return !root?0:(sum == root->val) + _dfs(sum - root->val, root->left) + _dfs(sum - root->val, root->right);
    }
};
