/* Title:
 * mergeSort
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stdio.h>
#include <unordered_map>

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
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k) {
        if (!pRoot) return pRoot;
        int n_left = getNodeNums(pRoot->left);
        if (n_left + 1 == k)
            return pRoot;
        else if (n_left + 1 > k)
            return KthNode(pRoot->left, k);
        else
            return KthNode(pRoot->right, k-n_left-1);
    }
    int getNodeNums(TreeNode* p) {
        if (!p) return 0;
        return getNodeNums(p->left) + getNodeNums(p->right) + 1;
    }
};


int main(int argc, char *argv[]) {

    return 0;
}
