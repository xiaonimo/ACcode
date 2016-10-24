/* Title:
 * 汉诺塔
 * left:存储原始hanoi，middle是中转站，right是移动完成的hanoi
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    printHanoi(stack<int> &s) {

    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        //这里对于空序列的判断根据题意来。
        if (sequence.empty()) return false;
        return VerifySquenceOfBST(sequence,0,sequence.size()-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence, int start, int last) {
        if (start >= last) return true;
        int root = sequence[last];
        int index = 0;
        for (int i = start;i<last;++i) {
            if (root>sequence[i])
                continue;
            index = i;
            for (;i<last;++i) {
                if (root>sequence[i])
                    return false;
            }
        }
        return VerifySquenceOfBST(sequence,start,index-1) &&
                VerifySquenceOfBST(sequence,index,last-1);
    }
};

int main() {
    Solution s;
    cout <<s.VerifySquenceOfBST(vector<int>{2,4,3,6,8,9,5});
}
