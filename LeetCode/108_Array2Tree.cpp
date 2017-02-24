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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _dfs(nums, 0, nums.size()-1);
    }
    TreeNode* _dfs(vector<int>& nums, int fst, int lat) {
        if (fst > lat)
            return nullptr;
        TreeNode *cur = new TreeNode(nums[(fst+lat)/2]);
        cur->left = _dfs(nums, fst, (fst+lat)/2-1);
        cur->right = _dfs(nums, (fst+lat)/2+1, lat);
        return cur;
    }
};