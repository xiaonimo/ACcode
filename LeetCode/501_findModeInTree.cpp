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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> hmap;
        int cnt = _dfs(root, hmap);
        vector<int> res;
        for (auto p:hmap) {
            if (p.second == cnt)
                res.push_back(p.first);
        }
        return res;
    }
    int _dfs(TreeNode* root, unordered_map<int, int> &hmap) {
        if (!root) return 0;
        hmap[root->val]++;
        return max(hmap[root->val], max(_dfs(root->right, hmap), _dfs(root->left, hmap)));
    }
};