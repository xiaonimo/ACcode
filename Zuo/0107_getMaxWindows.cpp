/* Title:
 *
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
    //这是O(N)的复杂度
    //也可以使用O(NW)复杂度
    vector<int> getMaxWindow(vector<int> nums, int w) {
        vector<int> res;
        if (nums.empty() || w < 1 || (int)nums.size()<w)
            return res;
        deque<int> qmax;
        for (int i=0;i<(int)nums.size();++i) {
            while (!qmax.empty() && nums[qmax.back()] <= nums[i]) {
                qmax.pop_back();
            }
            qmax.push_back(i);
            if (qmax.front() == i-w) {
                qmax.pop_front();
            }
            if (i >= w-1) {
                res.push_back(nums[qmax.front()]);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> res = s.getMaxWindow(vector<int>{4,3,5,4,3,3,6,7}, 3);
    for (auto num:res)
        cout<< num;

}
