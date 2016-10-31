/* Title:
 * 使用一个栈排序另一个栈
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    //
    void SortStack(stack<int> &s) {
        stack<int> st;
        while(!s.empty()) {
            int num = s.top();
            s.pop();
            if (st.empty() || num<=st.top())
                st.push(num);
            else {
                while (!st.empty() && num>st.top()) {
                    int numt = st.top();
                    st.pop();
                    s.push(numt);
                }
                st.push(num);
            }
        }
        while (!st.empty()) {
            s.push(st.top());
            st.pop();
        }
    }
    //简化版本
    void SortStack1(stack<int> &s) {
        stack<int> st;
        while(!s.empty()) {
            int num = s.top();
            s.pop();
            while (!st.empty() && num>st.top()) {
                int numt = st.top();
                st.pop();
                s.push(numt);
            }
            st.push(num);
        }
        while (!st.empty()) {
            s.push(st.top());
            st.pop();
        }
    }
};

int main() {
    stack<int> sta;
    sta.push(1);
    sta.push(5);
    sta.push(3);
    sta.push(2);
    sta.push(4);
    Solution s;
    s.SortStack1(sta);
    while (!sta.empty()) {
        cout << sta.top();
        sta.pop();
    }
    return 0;
}
