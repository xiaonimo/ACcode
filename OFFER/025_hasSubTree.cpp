/* Title:
 * 判断一棵树是不是另一棵树的子树
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2)
            return false;
        if (_hasSubtree(pRoot1, pRoot2))
            return true;

        return HasSubtree(pRoot1->left, pRoot2)||HasSubtree(pRoot1->right, pRoot2);
    }
    bool _hasSubtree(TreeNode* p1, TreeNode* p2) {
        if (!p1 && !p2) return true;
        else if (!p1 && p2) return false;
        else if (p1 && !p2) return true;
        else {
            if (p1->val!=p2->val) return false;
            return _hasSubtree(p1->left,p2->left) && _hasSubtree(p1->right,p2->right);
        }
    }
};

int main(int argc, char *argv[]) {


    return 0;
}
