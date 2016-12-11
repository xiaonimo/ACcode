/* Title:
 * 和为S的连续正整数序列
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5) return false;
        sort(begin(numbers), end(numbers));
        int index = 0;
        for (;index < (int)numbers.size();++index) {
            if (numbers[index] != 0) break;
        }
        int val = numbers[numbers.size()-1]- numbers[index];
        int in = numbers.size() - index;
        if (val + 1 < in )
            return false;
        else if (index >= val - in + 1)
            return true;
        else
            return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s1;
    cout << s1.IsContinuous(vector<int>{0,0,3,4,5});

    return 0;
}
