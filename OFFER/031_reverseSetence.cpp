/* Title:
 * 和为S的连续正整数序列
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty())
            return str;
        int i = 0, j = 0;
        while (j < (int)str.size()) {
            while (str[j] == ' ' && j < (int)str.size()) {
                ++j;
                i=j;
            }
            i = j;
            while (str[j] != ' ' && j < (int)str.size())
                ++j;
            _reverse(str, i, j-1);
        }
        _reverse(str, 0, str.size()-1);
        return str;
    }
    void _reverse(string &str, int i, int j) {
        if (i >= j) return;
        for (;i<j; ++i,--j) {
            swap(str[i], str[j]);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s1;
    cout << s1.ReverseSentence("l am a chinese student.");
    string a;
}
