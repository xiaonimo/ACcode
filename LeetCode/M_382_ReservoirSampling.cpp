/* Title:
 * Given a singly linked list, return a random node's value 
 * from the linked list. Each node must have the same probability of being chosen.
 * Follow up:
 * What if the linked list is extremely large and its length is unknown to you? 
 * Could you solve this efficiently without using extra space?

 * Example:

 * // Init a singly linked list [1,2,3].
 * ListNode head = new ListNode(1);
 * head.next = new ListNode(2);
 * head.next.next = new ListNode(3);
 * Solution solution = new Solution(head);
 // getRandom() should return either 1, 2, or 3 randomly. 
 //Each element should have equal probability of returning.solution.getRandom();
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<random>

using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 class Solution {
 private:
	 ListNode *head;
	 std::default_random_engine generator;
 public:
	 /** @param head The linked list's head.
	 Note that the head is guaranteed to be not null, so it contains at least one node. */
	 Solution(ListNode* head) {
		 this->head = head;
		 this->generator = std::default_random_engine();
	 }

	 /** Returns a random node's value. */
	 int getRandom() {
		 int res = head->val;
		 ListNode *h = head->next;
		 //这里注意，一定要重新声明一个变量保存头节点。
		 int num_base = 1;
		 while (h) {
			 std::uniform_int_distribution<int> rand_num(0, num_base);
			 if (rand_num(generator) == 0)
				 res = h->val;
			 ++num_base;
			 h = h->next;
		 }
		 return res;
	 }
 };

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/

int main(void)
{
	ListNode p1(1),p2(2),p3(3),p4(4),p5(5);
	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p4;
	p4.next = &p5;
	for (int i = 0; i < 10; ++i) {
		Solution s(&p1);
		cout << s.getRandom() << endl;
	}
	system("pause");
	return 0;
}
