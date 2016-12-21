/* Title:
 * 找到数字流中的中位数
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
private:
    priority_queue<int> lq;
    priority_queue<int> rq;
public:
    void Insert(int num) {
        if (lq.empty() || num < lq.top())
            lq.push(num);
        else
            rq.push(-num);
        if (lq.size()-rq.size() == 2) {
            rq.push(-lq.top());
            lq.pop();
        }
        if (rq.size()>lq.size()) {
            lq.push(-rq.top());
            rq.pop();
        }
    }

    double GetMedian() {
        return lq.size() == rq.size()?(lq.top()-rq.top())/2.0:(double)lq.top();
    }

};
 int main(int argc, char *argv[]) {
    Solution s;
    for (int i = 1;i <= 10;++i) {
        s.Insert(i);
        cout << s.GetMedian() <<endl;
    }

}

