/* Title:
 * 连续子数组的最大和
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

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max_sum = INT_MIN;
        int cur_sum = INT_MIN;
        for (auto num:array) {
            if (cur_sum < 0)//折两个if条件顺序不能变，否则不能处理全是负数的情况
                cur_sum = num;
            else
                cur_sum += num;
            if (cur_sum > max_sum)
                max_sum = cur_sum;
            cout << cur_sum << '\t' << max_sum <<endl;
        }
        return max_sum;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.FindGreatestSumOfSubArray(vector<int>{1,-3,3,10,-4,7,2,-5});
    return 0;
}
