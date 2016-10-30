/* Title:
 *
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <stdio.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //将一颗搜索二叉树转换为排好序的双向链表
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree)
            return pRootOfTree;
        TreeNode *pre = Convert(pRootOfTree->left);
        TreeNode *last = Convert(pRootOfTree->right);
        //cout << pre->val << endl;
        if (pre) {
            TreeNode *cur = pre;
            if (cur->right) {
                while (cur->right) {
                    cur = cur->right;
                }
            }
            cur->right = pRootOfTree;
            pRootOfTree->left = cur;
        }
        if (last) {
            pRootOfTree->right = last;
            last->left = pRootOfTree;
        }
        //cout << pre->val <<endl;
        return pre?pre:pRootOfTree;
    }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(0);
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(5);
    TreeNode *p6 = new TreeNode(6);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    Solution s;
    TreeNode *l = s.Convert(root);
    while (l) {
        cout << l->val;
        l = l->right;
    }

}
