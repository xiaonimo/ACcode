//实现一个栈，能够pop,push,getmin，
//时间复杂度O(1)

#include <iostream>
#include <stack>

class MyStack {
private:
    std::stack<int> sta_data;
    std::stack<int> sta_min;

public:
    int get_top() {
        assert(!sta_data.empty())
        return sta_data.top();
    }

    void my_push(int x) {
        sta_data.push(x);
        if (sta_min.empty()) sta_min.push(x);
        int _top = get_top();
        if (_top >= x) sta_min.push(x);
    }

    void my_pop() {
        int _top = get_top();
        if (_top == sta_min.top()) sta_min.pop();
    }

    int get_min() {
        assert(!sta_min.empty());
        return sta_min.top();
    }
};
