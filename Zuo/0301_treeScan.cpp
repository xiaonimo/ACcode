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
    //3ms.
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root)//主函数中对空树做出了判断，之后的空树情况不在讨论
            dfsInOrder(root, res);
        return res;
    }
    void dfsInOrder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) return;
        dfsInOrder(root->left, res);
        res.push_back(root->val);
        dfsInOrder(root->right, res);
        return;
    }
    void dfsPreOrder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) return;
        res.push_back(root->val);
        dfsPreOrder(root->left, res);
        dfsPreOrder(root->right, res);
        return;
    }
    void dfsPostOrder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) return;
        dfsPostOrder(root->left, res);
        dfsPostOrder(root->right, res);
        res.push_back(root->val);
        return;
    }
    //循环方式的先序遍历
    void loopPreOrder(TreeNode *root, vector<int> &res) {
        stack<TreeNode*> sta;
        sta.push(root);
        while (!sta.empty()) {
            TreeNode *tmp = sta.top();
            sta.pop();
            res.push_back(tmp->val);
            if (tmp->left)
                sta.push(tmp->left);
            if (tmp->right)
                sta.push(tmp->right);
        }
        return;
    }
    //循环方式的中序遍历
    void loopInOrder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        stack<TreeNode*> sta;
        TreeNode *cur = root;
        while (!sta.empty() || cur != nullptr) {
            if (cur) {
                sta.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode *tmp = sta.top();
                sta.pop();
                res.push_back(tmp->val);
                cur = tmp->right;
            }
        }
        return;
    }
    //循环方式的后序遍历1,使用两个栈
    void loopPostOrder1(TreeNode *root, vector<int> &res) {
        if (!root) return;
        stack<TreeNode*> sta1;
        stack<TreeNode*> sta2;
        sta1.push(root);
        while (!sta1.empty()) {
            TreeNode *tmp = sta1.top();
            sta1.pop();
            sta2.push(tmp);
            if (tmp->left)
                sta1.push(tmp->left);
            if (tmp->right)
                sta1.push(tmp->right);
        }
        while (!sta2.empty()) {
            TreeNode *tmp = sta2.top();
            sta2.pop();
            res.push_back(tmp->val);
        }
        return;
    }
    //循环方式的后序遍历2,使用一个栈
    void loopPostOrder2(TreeNode *root, vector<int> &res) {
        if (!root) return;
        stack<TreeNode*> sta;
        TreeNode *lastpop = root;
        TreeNode *statop = nullptr;
        sta.push(root);
        while (!sta.empty()) {
            statop = sta.top();
            if (statop->left && lastpop != statop->left && lastpop != statop->right)
                sta.push(statop->left);
            else if (statop->right && lastpop != statop->right)
                sta.push(statop->right);
            else {
                res.push_back(statop->val);
                sta.pop();
                lastpop = statop;
            }
        }
        return;
    }
    //Morris中序遍历
    void morrisInOrder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        TreeNode* cur1 = root;
        TreeNode* cur2 = nullptr;
        while (cur1) {
            cur2 = cur1->left;
            if (cur2) {
                while (cur2->right && cur2->right!=cur1) {
                    cur2 = cur2->right;
                }
                if (!cur2->right) {
                    cur2->right = cur1;
                    cur1 = cur1->left;
                    continue;
                }
                else {
                    cur2->right = nullptr;
                }
            }
            res.push_back(cur1->val);
            cur1 = cur1->right;
        }
    }
    //Morris先序遍历
    void morrisPreOrder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        TreeNode *cur1 = root;
        TreeNode *cur2 = nullptr;
        while (cur1) {
            cur2 = cur1->left;
            if (cur2) {
                while (cur2->right && cur2->right != cur1) {
                    cur2 = cur2->right;
                }
                if (!cur2->right) {
                    cur2->right = cur1;
                    res.push_back(cur1->val);
                    cur1 = cur1->left;
                    continue;
                }
                else {
                    cur2->right = nullptr;
                }
            }
            else {
                res.push_back(cur1->val);
            }
            cur1 = cur1->right;
        }
    }
    //Morris后序遍历
    void morrisPostOrder(TreeNode *root, vector<int> &res) {

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
    vector<int> res;
    s.morrisPreOrder(root, res);
    for (auto m:res)
        cout << m;

    return 0;
}
