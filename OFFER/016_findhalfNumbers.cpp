/* Title:
 * 数组中有一个数字出现的次数超过数组长度的一半，
 * 请找出这个数字。例如输入一个长度为9的数组
 * {1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
 * 超过数组长度的一半，因此输出2。如果不存在则输出0。
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        int res = numbers[0];
        int cnt = 1;
        for (int i = 1;i<numbers.size();++i) {
            if (cnt == 0) {
                res = numbers[i];
                ++cnt;
                continue;
            }
            if (res == numbers[i])
                ++cnt;
            else
                --cnt;
        }
        cnt = 0;
        for (auto num:numbers) {
            if (num == res)
                ++cnt;
        }
        return cnt>(numbers.size()/2)?res:0;

    }
};

int main(int argc, char *argv[]) {

    Solution s;
    cout << s.MoreThanHalfNum_Solution(vector<int>{1});
    return 0;
}
