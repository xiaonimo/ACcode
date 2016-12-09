/* Title:
 * 和为S的连续正整数序列
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty()) return str;
        n = n%str.size();
        return string(begin(str)+n, end(str)) + string(begin(str), begin(str)+n);
    }
    string LeftRotateString1(string str, int n) {
        if (str.empty()) return str;
        return _reverse(_reverse(string(begin(str), begin(str)+n))+_reverse(string(begin(str)+n, end(str))));
    }
    string _reverse(string str) {
        for (int i = 0, j = str.size()-1;i<j;++i,--j)
            swap(str[i], str[j]);
        return str;
    }
};

int main(int argc, char *argv[]) {
    Solution s1;
    cout << s1.LeftRotateString1(string("abcXYZdef"), 3);

}
