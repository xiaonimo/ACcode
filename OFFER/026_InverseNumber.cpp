/* Title:
 * 判断一棵树是不是另一棵树的子树
 */

#include <iostream>
#include <vector>
#include <stdio.h>
#include <windows.h>
using namespace std;

class Solution{
public:
    int InversePairs(vector<int> data) {
        if (data.empty()) return 0;
        vector<int> tmp(data.size(), -1);
        int res = _inversePairs(data, tmp, 0, data.size()-1);
        return res;
    }
    int _inversePairs(vector<int> &data, vector<int> &tmp, int s, int e) {
        if (s >= e) {
            tmp[s] = data[s];
            return 0;
        }
        int m = s + (e-s)/2;
        int c1 = _inversePairs(data, tmp, s, m);
        int c2 = _inversePairs(data, tmp, m+1, e);
        int c3 = _merge(tmp, tmp, s, m, e);
        return c1+c2+c3;
    }
    int _merge(vector<int> data, vector<int> &tmp, int s, int m, int e) {
        int res = 0;
        int i = m, j = e;
        int tmp_index = e;
        while (i>=s && j>=m+1) {
            if (data[i] > data[j]) {
                res += j-m;
                tmp[tmp_index--] = data[i--];
            }
            else
                tmp[tmp_index--] = data[j--];
        }
        while (i>=s)
            tmp[tmp_index--] = data[i--];
        while (j>=m+1)
            tmp[tmp_index--] = data[j--];
        return res%1000000007;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.InversePairs(vector<int>{364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575});
}
