/* Title:
* 机器人运动路径
*/

#include <iostream>
#include <vector>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Converter {
public:
    ListNode* treeToList(TreeNode* root) {
        // write code here
       	ListNode *head = new ListNode(-1);
        ListNode *thead = head;
        _transfer(head, root);
        ListNode* res = thead->next;
        delete thead;
        return res;
    }
    void _transfer(ListNode* &cur, TreeNode* root) {
        if (!root)
            return;
        _transfer(cur, root->left);
        cur->next = new ListNode(root->val);
        cur = cur->next;
        _transfer(cur, root->right);
        return;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    for (unsigned i = 0;i<100000000;++i) {
        f4(s);
    }
	return 0;
}

