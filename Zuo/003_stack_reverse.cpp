//递归操作逆序一个栈,仅用栈的操作
#include <iostream>
#include <stack>

using namespace std;

void stack_bottom(stack<int> &sta, int x) {
    if (sta.empty()) {
        sta.push(x);
        return;
    }
    int _top = sta.top();
    sta.pop();
    stack_bottom(sta, x);
    sta.push(_top);
}


void stack_reverse(stack<int> &sta) {
    if (sta.size() <= 1) return;
    int _top = sta.top();
    sta.pop();
    stack_reverse(sta);
    stack_bottom(sta, _top);
}

int main() {
    stack<int> sta;
    for (int i=0;i<10;++i) {
        sta.push(i);
    }
    stack_reverse(sta);
    while (!sta.empty()) {
        cout << sta.top() <<endl;
        sta.pop();
    }
}
