/* Title:
 * ��ԭ��
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //����ǰ����������������������Ľṹ�����������ظ����֣�
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if (pre.empty()) return nullptr;
        return ConstructBinaryTree1(pre, 0, pre.size(), in, 0, in.size());
    }
    struct TreeNode* ConstructBinaryTree(vector<int> pre, int pfirst, int plast,
                                         vector<int> in, int ifirst, int ilast) {
        TreeNode *h = new TreeNode(pre[pfirst]);
        if (pfirst >= plast || ifirst >= ilast)
            return nullptr;
        for (int i = ifirst;i<ilast;++i) {
            if (pre[pfirst] == in[i]) {
                h->left = ConstructBinaryTree(pre, pfirst+1, pfirst+i-ifirst+1,
                                              in, ifirst, i);
                h->right = ConstructBinaryTree(pre, pfirst+i-ifirst+1, plast,
                                               in, i+1, ilast);
                break;
            }
        }
        return h;
    }

    //���ݺ������������������������Ľṹ
    struct TreeNode* ConstructBinaryTree1(vector<int> post, int pfirst, int plast,
                                         vector<int> in, int ifirst, int ilast) {
        TreeNode *h = new TreeNode(post[plast-1]);
        if (pfirst >= plast || ifirst >= ilast)
            return nullptr;
        for (int i = ifirst;i<ilast;++i) {//ע�⣬�����i�Ǵ�ifirst��������Ҫע��ݹ�ʱ����±�
            if (post[plast-1] == in[i]) {
                h->left = ConstructBinaryTree1(post, pfirst, pfirst+i-ifirst,
                                              in, ifirst, i);
                h->right = ConstructBinaryTree1(post, pfirst+i-ifirst, plast-1,
                                               in, i+1, ilast);
                break;
            }
        }
        return h;
    }
};
void print(TreeNode *root) {
    if (root == nullptr) return;
    cout << root->val;
    print(root->left);
    print(root->right);
    //cout << root->val;
    return;
}
int main() {
    Solution s;
    TreeNode *h = s.reConstructBinaryTree(vector<int>{7,4,2,5,8,6,3,1},vector<int>{4,7,2,1,5,3,8,6});
    print(h);
    return 0;
}
