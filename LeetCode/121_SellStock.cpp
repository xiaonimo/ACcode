/* Say you have an array for which the ith element is the price of a given stock 
 * on day i.

 * If you were only permitted to complete at most one transaction (ie, buy one and 
 * sell one share of the stock), design an algorithm to find the maximum profit.

 * Example 1:
 * Input: [7, 1, 5, 3, 6, 4]
 * Output: 5
 * max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
 
 * Example 2:
 * Input: [7, 6, 4, 3, 1]
 * Output: 0
 *In this case, no transaction is done, i.e. max profit = 0.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) {
			return 0;
		}
		int res = 0;
		int min = prices[0];
		for (int i = 0; i < prices.size(); ++i) {
			if (min < prices[i] ) {
				int tmp = prices[i] - min;
				res = tmp>res ? tmp : res;
			}
			else {
				min = prices[i];
			}
		}
		return res;
	}
	//short and clean
	int maxProfit1(vector<int>& prices) {
		int res = 0;
		int min_val = INT_MAX;//
		for (int i = 0; i < prices.size(); ++i) {
			min_val = min(min_val, prices[i]);
			res = max(res, prices[i] - min_val);
		}
		return res;
	}
};
int main()
{
	vector<int> p = { 7, 1, 5, 3, 6, 4 };
	Solution s = Solution();
	cout << s.maxProfit1(p);
	system("pause");
	return 0;
}