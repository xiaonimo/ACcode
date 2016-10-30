/* Title:
 * Given an array containing n distinct numbers
 * taken from 0, 1, 2, ..., n, find the one that
 * is missing from the array.

 * For example,
 * Given nums = [0, 1, 3] return 2.

 * Note:
 * Your algorithm should run in linear runtime complexity.
 * Could you implement it using only constant extra space complexity?
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

class Solution {
public:
    //use bit operation
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i = 0;

        for (const auto num:nums) {
            result ^= nums[i];
            result ^= i;
            ++i;
        }
        return result;
    }

    int missingNumber1(vector<int>& nums) {
        int sum = 0;
        int max_num = 0;
        for (auto num:nums) {
            sum+=num;//overflow
            if (num>max_num)
                max_num = num;
        }
        int sumt = max_num*(max_num+1)/2;
        return sumt == sum?(max_num<nums.size()?max_num+1:0):sumt-sum;
    }
};

int main() {
    int a = 0;
    cout << (a^(a+1));

}
