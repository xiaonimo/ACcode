/* Title:
 * 只使用递归操作和栈操作来逆序栈
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    //递归的主体部分
    void reverseStack(stack<int> &s) {
        if (s.empty()) return;
        int num = getAndDeleteBottom(s);
        reverseStack(s);
        s.push(num);
    }
    //递归的获取栈的最后一个元素并删除
    int getAndDeleteBottom(stack<int> &s) {
        int num1 = s.top();
        s.pop();
        if (s.empty())
            return num1;
        int num2 = getAndDeleteBottom(s);
        s.push(num1);
        return num2;
    }
};
int main() {
    Solution s;
    stack<int> sta;
    sta.push(1);
    sta.push(2);
    sta.push(3);
    sta.push(4);
    sta.push(5);

    s.reverseStack(sta);
    while (!sta.empty()) {
        cout << sta.top();
        sta.pop();
    }
}
