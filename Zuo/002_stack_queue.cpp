//使用两个栈形成一个队列

#include <iostream>
#include <stack>

class stack_2queue {
private:
    std::stack<int> sta1;
    std::stack<int> sta2;

public:
    void my_push(int x) {
        while (!sta2.empty()) {
            int _top = sta2.top();
            sta2.pop();
            sta1.push(_top);
        }
        sta1.push(x);
    }
    void my_pop() {
        while (!sta2.empty()) {
            int _top = sta2.top();
            sta2.pop();
            sta1.push(_top);
        }
        assert(!sta1.empty())
        sta1.pop();
    }
    int my_front() {
        while (!sta1.empty()) {
            int _top = sta1.top();
            sta2.push(_top);
            sta1.pop();
        }
        assert(!sta2.empty());
        return sta2.top();
    }
    int my_back() {
        while (!sta2.empty()) {
            int _top = sta2.top();
            sta1.push(_top);
            sta2.pop();
        }
        assert(!sta1.empty());
        return sta1.top();
    }
};
