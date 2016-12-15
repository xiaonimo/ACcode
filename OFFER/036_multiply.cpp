/* Title:
 * 构建乘积数组
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //构造存储中间值的辅助数组
    vector<int> multiply(const vector<int>& A) {
        if (A.empty())
            return A;
        vector<int> _front(A.size());
        vector<int> _back(A.size());
        _front[0] = 1;
        for (int i = 1; i<(int)_front.size();++i)
            _front[i] = _front[i-1]*A[i-1];

        _back[_back.size()-1] = 1;
        for (int i = (int)_back.size()-2;i>=0;--i)
            _back[i] = _back[i+1] * A[i+1];

        vector<int> res(A.size());
        for (int i = 0;i<(int)res.size();++i) {
            res[i] = _front[i]*_back[i];
        }
        return res;
    }

    //连乘的方式，空间消耗为O(1)
    vector<int> multiply1(const vector<int>& A) {
        vector<int> res(A.size());
        res[0] = 1;
        for (int i = 1;i<(int)res.size();++i) {
            res[i] = res[i-1]*A[i-1];
        }
        int tmp = 1;
        for (int i = (int)res.size()-2;i>=0;--i) {
            tmp *= A[i+1];
            res[i] *= tmp;
        }
        return res;
    }

};


 int main(int argc, char *argv[]) {
    Solution s;
    for (auto n:s.multiply({1,2,3,4,5,6,7,8,9,10}))
        cout << n <<endl;

    for (auto n:s.multiply1({1,2,3,4,5,6,7,8,9,10}))
        cout << n <<endl;
}

