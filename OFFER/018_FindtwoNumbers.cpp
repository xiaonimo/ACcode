/* Title:
 * 输入一个递增排序的数组和一个数字S，
 * 在数组中查找两个数，使得他们的和正好是S，
 * 如果有多对数字的和等于S，输出两个数的乘积最小的。
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

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int i = 0, j=array.size()-1;
        while (i<j) {
            if (array[i]+array[j] == sum) {
                if (res.empty()) {
                    res.push_back(array[i]);
                    res.push_back(array[j]);
                }
                if (array[i]*array[j] < res[0]*res[1]) {
                    res[0] = array[i];
                    res[1] = array[j];
                }
                ++i;
            }
            else if (array[i]+array[j] < sum) {
                ++i;
            }
            else {
                --j;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {

    Solution s;
    vector<int> res=s.FindNumbersWithSum(vector<int>{1,2,3,4,5,6,7}, 8);
    cout << res[0] << res[1];

    return 0;
}
