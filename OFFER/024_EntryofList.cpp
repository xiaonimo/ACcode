/* Title:
 * »·Èë¿Ú
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
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop1(ListNode* pHead) {
        unordered_map<ListNode*, int> hmap;
        while (pHead) {
            if (hmap[pHead])
                return pHead;
            hmap[pHead]++;
            pHead = pHead->next;
        }
        return nullptr;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (!pHead || !pHead->next)
            return nullptr;
        ListNode* fast = pHead;
        ListNode* slow = pHead;

        while (true) {
            if (!slow || !slow->next)
                return nullptr;
            fast = fast->next;
            slow = slow->next->next;
            if (fast == slow)
                break;
        }

        fast = pHead;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    return 0;
}
