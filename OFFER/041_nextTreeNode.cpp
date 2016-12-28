/* Title:
 * 找到字符流中第一个只出现一次的字符
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == nullptr)
            return pNode;
        if (pNode->right == nullptr) {
            while (pNode->next != nullptr) {
                TreeLinkNode*cur = pNode->next;
                if (cur->left == pNode) return cur;
                pNode = pNode->next;
            }
            return nullptr;
        }
        else {
            TreeLinkNode* cur = pNode->right;
            while (cur->left) cur = cur->left;
            return cur;
        }
    }
};
 int main(int argc, char *argv[]) {
    Solution s;
    TreeLinkNode* p1 = new TreeLinkNode(101);
    TreeLinkNode* p2 = new TreeLinkNode(201);
    TreeLinkNode* p3 = new TreeLinkNode(301);
    TreeLinkNode* p4 = new TreeLinkNode(401);
    TreeLinkNode* p5 = new TreeLinkNode(501);
    TreeLinkNode* p6 = new TreeLinkNode(601);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p3->left = p5;
    p3->right = p6;

    TreeLinkNode* cur = s.GetNext(p6);
    if (cur == nullptr)
        cout << "nullptr" <<endl;
    else
        cout << cur->val <<endl;


    return 0;
}

