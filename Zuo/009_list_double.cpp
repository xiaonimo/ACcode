#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

struct DListNode {
    int val;
    DListNode* next;
    DListNode* pre;
    DListNode(int x):val(x), next(nullptr), pre(nullptr){}
};

//打印链表
void list_common(ListNode* head) {
    if (!head) return;
    cout << head->val;
    list_common(head->next);
}

//打印有序链表的公共部分
void list_common(ListNode* h1, ListNode* h2) {
    if (!h1 || !h2) return;
    if (h1->val == h2->val) cout << h1->val;
    else if (h1->val > h2->val) list_common(h1, h2->next);
    else list_common(h1->next, h2);
}

//反转双向链表
void DListNode_reverse(DListNode* head) {
    if (!head || !head->next) return head;
    DListNode* res = DListNode_reverse(head->next);
    head->next->next = head;
    head->pre = head->next;
    head->next = nullptr;
    return res;
}

void DListNode_reverse_loop(DListNode* head) {
    if (!head || !head->next) return head;
    DListNode* cur = head->next;
    DListNode* pre = head;
    while (cur) {
        DListNode* tmp = cur->next;
        cur->next = pre;
        pre->next = cur;
        pre = cur;
        cur = tmp;
    }
    return pre;
}








