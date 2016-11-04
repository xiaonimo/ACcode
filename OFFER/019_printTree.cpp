/* Title:
 * 请实现一个函数按照之字形打印二叉树，
 * 即第一行按照从左到右的顺序打印，
 * 第二层按照从右至左的顺序打印，
 * 第三行按照从左到右的顺序打印，其他行以此类推。
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
    //使用一个队列 + reverse()函数
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        while (!q.empty()) {
            vector<int> vec;
            int sz = (int)q.size();

            for (int i = 0;i<sz;++i) {
                TreeNode* tmp = q.front();
                q.pop();
                vec.push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            res.push_back(vec);
        }

        bool flag = false;
        for (auto &v:res) {
            if (flag) {
                reverse(begin(v), end(v));
                flag = !flag;
            }
            else
                flag = !flag;
        }
        return res;
    }
    //使用两个栈，不需要reverse
    vector<vector<int> > Print1(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) return res;
        stack<TreeNode*> s1,s2;
        s1.push(pRoot);
        while (!s1.empty() || !s2.empty()) {
            vector<int> vec;
            //s1是从右向左存储
            if (s1.empty()) {
                while (!s2.empty()) {
                    TreeNode* t = s2.top();
                    s2.pop();
                    vec.push_back(t->val);
                    if (t->right)
                        s1.push(t->right);
                    if (t->left)
                        s1.push(t->left);
                }
            }
            else {
                while (!s1.empty()) {
                    TreeNode* t = s1.top();
                    s1.pop();
                    vec.push_back(t->val);
                    if (t->left)
                        s2.push(t->left);
                    if (t->right)
                        s2.push(t->right);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p3 = new TreeNode(3);
    p1->left = p2;
    p1->right = p3;
    Solution s;
    vector<vector<int>> a = s.Print(p1);
    for (auto v:a) {
        for (auto n:v)
            cout<< n;
    }
    return 0;
}
