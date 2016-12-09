/* Title:
 * 和为S的连续正整数序列
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if (sum < 3) return res;
        int low = 1;
        int high = 2;
        int cursum = 3;

        while (low < high && low < (sum+1)/2) {
            if (cursum < sum) {
                ++high;
                cursum += high;
            }
            else if (cursum > sum) {
                cursum -= low;
                ++low;
            }
            else {
                vector<int> seq;
                for (int i = low; i<=high; ++i)
                    seq.push_back(i);
                res.push_back(seq);
                ++high;
                cursum += high;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s1;
    for (auto v:s1.FindContinuousSequence(100)) {
        for (auto c:v)
            cout << c;
        cout << endl;
    }

}
