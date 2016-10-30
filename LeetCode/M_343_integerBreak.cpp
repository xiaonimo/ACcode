/* Title:
 * Given a positive integer n, break it into the sum
 * of at least two positive integers and maximize the
 * product of those integers.
 * Return the maximum product you can get.
 * For example, given n = 2, return 1 (2 = 1 + 1);
 * given n = 10, return 36 (10 = 3 + 3 + 4).

 * Note: You may assume that n is not less than 2 and not larger than 58.
 *
 */

#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    //分解3.多个3相乘会使得结果最大化
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int res = 1;
        while (n>=5) {
            res *=3;
            n-=3;
        }
        return res*n;
    }
    /* why?
     * x^(n/x)的最大值。求导数，当x=e时候取最大值。
     */
};
