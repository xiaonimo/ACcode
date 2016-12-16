/* Title:
 * 构建乘积数组
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode *newhead = new ListNode(-1);
        newhead->next = pHead;
        ListNode *curhead = newhead;
        while (curhead->next) {
            ListNode *cur = curhead->next;
            bool dup = false;
            while (cur->next && (cur->val==cur->next->val)) {
                dup = true;
                cur = cur->next;
            }
            if (dup) {
                curhead->next = cur->next;
            }
            else {
                curhead->next = cur;
                curhead = curhead->next;
            }
        }
        curhead = newhead->next;
        delete newhead;
        return curhead;
    }
};

 int main(int argc, char *argv[]) {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(2);
    ListNode *p4 = new ListNode(3);
    ListNode *p5 = new ListNode(3);
    ListNode *p6 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    Solution s;
    ListNode *res = s.deleteDuplication(p1);
    while (res) {
        cout << res->val <<endl;
        res = res->next;
    }
}

