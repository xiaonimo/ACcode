/* Given an array of size n, find the majority element. 
 * The majority element is the element that appears more than [n/2] times.

 * You may assume that the array is non-empty 
 * and the majority element always exist in the array.
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	//16ms,use 2 vars to imitate the stack.
	int majorityElement(vector<int>& nums) {
		int res = 0;
		int cnt = 0;
		
		for (auto i : nums) {
			if (cnt == 0 ) {
				res = i;
				++cnt;
			}
			else if (res != i) {
				--cnt;
			}
			else {
				++cnt;
			}
		}
		return res;
	}
	//use stack,24ms
	int majorityElement1(vector<int>& nums) {
		stack<int> s;
		for (auto i:nums) {
			if (s.empty() || i == s.top()) {
				s.push(i);
			}
			else {
				s.pop();
			}
		}
		return s.top();
	}
};
int main()
{
	Solution s = Solution();
	int a[] = {6,5,5};
	vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
	cout << s.majorityElement(nums) << endl;

	system("pause");
	return 0;
}