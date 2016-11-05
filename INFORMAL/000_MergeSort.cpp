/* Title:
 * mergeSort
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    //first是第一个元素的下标，last是最后有一个元素的下标
    void _mergeSort(vector<int> &nums, int first, int last) {
        if (last <= first) return;

        int mid = first+(last-first)/2;
        _mergeSort(nums, first, mid);
        _mergeSort(nums, mid+1, last);
        _merge(nums, first, mid, last);
    }
    void _merge(vector<int> &nums, int first, int mid, int last) {
        int f1 = first, f2 = mid+1;
        int e1 = mid, e2 = last;
        vector<int> tmp;
        while (f1<=e1 && f2<=e2) {
            if (nums[f1] <= nums[f2]) {
                tmp.push_back(nums[f1]);
                ++f1;
            }
            else {
                tmp.push_back(nums[f2]);
                ++f2;
            }
        }
        while (f1 <= e1) {
            tmp.push_back(nums[f1]);
            ++f1;
        }
        while (f2 <= e2) {
            tmp.push_back(nums[f2]);
            ++f2;
        }
        int i = first;
        for (auto n:tmp) {
            nums[i++] = n;
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> a{3,6,4,7,9,8,1,2,5};
    Solution s;
    s._mergeSort(a, 0, a.size()-1);
    for (auto n:a) cout << n;
    return 0;
}
