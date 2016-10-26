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

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    //O(n*n)复杂度
    RandomListNode* Clone(RandomListNode* pHead) {
        if (pHead == nullptr) return pHead;
        RandomListNode *newHead = new RandomListNode(pHead->label);
        RandomListNode *newh = newHead;
        RandomListNode *pt = pHead;
        //先复制链表和next指针
        while (pt->next) {
            RandomListNode *tmp = new RandomListNode(pt->next->label);
            newh->next = tmp;
            newh = newh->next;
            pt = pt->next;
        }

        newh = newHead;//变量复用一下
        pt = pHead;
        while (newh) {//遍历一次链表，对每个节点找到random指针
            int step = 0;
            RandomListNode *pt2 = pHead;
            while (pHead != pt2->random)
                ++step;//记录步数
            RandomListNode *newr2 = newHead;
            while (step--)
                newr2 = newr2->next;
            newh->random = newr2;
            newh = newh->next;
            pt = pt->next;
        }
        return newHead;
    }
    //map关联
    RandomListNode* Clone1(RandomListNode* pHead) {
        if (pHead == nullptr) return pHead;
        map<RandomListNode*, RandomListNode*> hmap;
        RandomListNode *newHead = new RandomListNode(pHead->label);
        RandomListNode *newh = newHead;
        RandomListNode *pt = pHead;
        hmap[pt] = newh;
        //先复制链表和next指针
        while (pt->next) {
            RandomListNode *tmp = new RandomListNode(pt->next->label);
            newh->next = tmp;
            hmap[pt->next] = newh->next;
            newh = newh->next;
            pt = pt->next;
        }

        newh = newHead;//变量复用一下
        pt = pHead;
        while (newh) {//遍历一次链表，对每个节点找到random指针
            newh->random = hmap[pt->random];
            pt = pt->next;
            newh = newh->next;
        }
        return newHead;
    }
    //next指针关联
    RandomListNode* Clone2(RandomListNode* pHead) {
        if (pHead == nullptr) return nullptr;
        RandomListNode *pt = pHead;
        //生成链表，只复制label和next
        while (pt) {
            RandomListNode *tmp = new RandomListNode(pt->label);
            tmp->next = pt->next;
            pt->next = tmp;
            pt = tmp->next;
        }
        //修改random指针
        pt = pHead;
        while (pt) {
            if (pt->random) {
                pt->next->random = pt->random->next;
            }
            pt = pt->next->next;
        }
        //把链表拆分成两部分
        RandomListNode *res = pHead->next;
        RandomListNode *cur = res;
        pt = pHead;
        pt->next = cur->next;
        pt = pt->next;
        while (pt) {
            cur->next = pt->next;
            cur = cur->next;
            pt->next = cur->next;
            pt = pt->next;
        }
        return res;
    }
};

int main() {

}
