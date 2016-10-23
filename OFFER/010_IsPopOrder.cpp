/* Title:
 * 栈，给定输入序列，给定弹出序列，判断输出序列是否有可能产生。
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.empty()) return false;
        vector<int> vec;
        for (int i = 0,j=0;i<(int)pushV.size();++i) {
            vec.push_back(pushV[i]);
            while (!vec.empty() && vec.back() == popV[j]) {
                vec.pop_back();
                ++j;
            }
        }
        return vec.empty();
    }
};

int main() {
    Solution s;
    cout << s.IsPopOrder(vector<int>{1,2,3,4,5}, vector<int>{4,3,5,1,2});
    return 0;
}
