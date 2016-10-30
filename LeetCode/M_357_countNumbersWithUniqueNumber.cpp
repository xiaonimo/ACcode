/**Title:
 * Given a non-negative integer n,
 * count all numbers with unique digits, x, where 0 ≤ x < 10^n.

 * Example:
 * Given n = 2, return 91. (The answer should be the total
 * numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 */
#include<iostream>  
#include<vector>
#include<unordered_map>
#include <queue>
#include<algorithm>

using namespace std;
class Solution {
public:
	//TLE
	int countNumbersWithUniqueDigits(int n) {
		int cnt = 0;
		int cur_num = 0, max_num = (int)pow(10, n);
		while (cur_num < max_num) {
			int num = cur_num;
			int digit = 0;
			unordered_map<int, int> hmap;
			while (num) {
				digit = num % 10;
				if (hmap[digit]) {
					++cnt;
					break;
				}
				++hmap[digit];
				num /= 10;
			}
			++cur_num;
		}
		return max_num - cnt;
	}
	//根据题意，n相当于数字的最大位数
	//求解过程是DP过程。
	int countNumbersWithUniqueDigits1(int n) {
		if (n == 0) return 1;
		if (n == 1) return 10;
		int res = 10;
		int dp_num = 9;
		int factor = 9;
		int num_len = 2;
		while (num_len <= n) {
			dp_num *= factor;
			--factor;
			res += dp_num;
			++num_len;
		}
		return res;
	}
};

int main(void)
{
	Solution s;
	cout << s.countNumbersWithUniqueDigits1(2);
	system("pause");
	return 0;
}
