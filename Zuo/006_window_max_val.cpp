//移动窗口最大值
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> window_max_val(vector<int> vec, int w) {
    if (vec.empty()) return vec;
    vector<int> res;
    deque<int> index;
    for (int i = 0; i < (int)vec.size(); ++i) {
        while (!index.empty() && vec[index.back()] <= vec[i]) {
            index.pop_back();
        }
        index.push_back(i);
        if (index.front() == i-w) index.pop_front();
        if (i>=w-1) {
            res.push_back(vec[index.front()]);
        }
    }
    return res;
}

int main() {
    for (auto n:window_max_val(vector<int>{4,3,5,4,3,3,6,7}, 3)) {
        cout << n <<endl;
    }
}
