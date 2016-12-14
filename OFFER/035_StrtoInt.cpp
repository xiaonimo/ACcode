/* Title:
 * 约瑟夫环问题
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        if (!_isValid(str))
            return 0;
        int rate = 1;
        int res = 0;
        for (int i = str.size()-1;i>=0;--i) {
            if (isdigit(str[i]))
                res += rate*(str[i]-'0');
            else if (str[i] == '-')
                res = -res;
            else {

            }
            rate *= 10;
        }
        return res;
    }
    bool _isValid(string str) {
        if (str.empty())
            return false;
        for (int i = 0;i<(int)str.size();++i) {
            if ((isdigit(str[i])) || (str[i]=='+' && i==0) || (str[i] =='-' && i == 0 )||(str[i] == 'e'))
                continue;
            return false;
        }
        return true;
    }
};


 int main(int argc, char *argv[]) {

    Solution s;
    cout << s.StrToInt("-2349");

    return 0;
}

