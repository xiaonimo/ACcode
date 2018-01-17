#include <stack>
#include <vector>
#include <iostream>

using namespace std;

void stack_sort(stack<int> &sta) {
    stack<int> help;
    while (!sta.empty()) {
        int _top = sta.top();
        sta.pop();
        if (help.empty() || _top >= help.top()) {
            help.push(_top);
        } else {
            while (!help.empty() && _top < help.top()) {
                sta.push(help.top());
                help.pop();
            }
            help.push(_top);
        }
    }
    while (!help.empty()) {
        sta.push(help.top());
        help.pop();
    }
}

int main() {
    vector<int> a{2,3,5,34,8,3,8,3};
    stack<int> sta;
    for (auto i:a) sta.push(i);
    stack_sort(sta);
    while (!sta.empty()) {
        cout << sta.top() <<endl;
        sta.pop();
    }
}
