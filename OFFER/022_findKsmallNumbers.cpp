/* Title:
 * 输入两个链表，找出它们的第一个公共结点。
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
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k<=0) return vector<int>();
        return _partition(input, 0, input.size()-1, k);
    }
    vector<int> _partition(vector<int> &input, int first, int last, int k) {
        vector<int> res;
        if (k<=0)
            return res;
        if (last<=first) {
            res.push_back(input[first]);
            return res;
        }
        int i = first, j = last;
        int tmp = input[i];
        while (i<j) {
            while (i<j && input[j]>=tmp) --j;
            input[i] = input[j];
            while (i<j && input[i]<=tmp) ++i;
            input[j] = input[i];
        }
        input[i] = tmp;
        if (i-first > k-1) {
            return _partition(input, first, i, k);
        }
        for (int n=first;n<=i;++n) {
            res.push_back(input[n]);
        }
        if (i-first == k-1)
            return res;
        vector<int> pres = _partition(input, i+1, last, k-i+first-1);
        for (auto v:pres)
            res.push_back(v);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> a{4,5,1,6,2,7,3,8,3,4,7,9,12,2,2,1,1,1};
    vector<int> res = s.GetLeastNumbers_Solution(a, -1);
    for (auto n:res) {
        cout << n;
    }
    return 0;
}
