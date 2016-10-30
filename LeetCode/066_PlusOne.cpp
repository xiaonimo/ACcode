/* Given a non-negative number represented as an array of digits, 
 * plus one to the number.

 * The digits are stored such that the most significant digit is 
 * at the head of the list.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0 ; --i) {
			if ((++digits[i]) != 10)
				break;
			digits[i] = 0;
		}
		if (digits[0] == 0)
			digits.insert(digits.begin(), 1);
		return digits;
	}
	//simplify
	vector<int> plusOne1(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; --i) {
			if (digits[i] != 9) {
				++digits[i];
				return digits;
			}
			digits[i] = 0;
		}
		if (digits[0] == 0) {
			digits[0] = 1;
			digits.push_back(0);
		}
		return digits;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> a{ 9, 9, 9 };
	vector<int> b = s.plusOne(a);
	for (auto i : b)
		cout << i;
	system("pause");
	return 0;
}