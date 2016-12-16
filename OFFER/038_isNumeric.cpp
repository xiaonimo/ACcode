/* Title:
 * 构建乘积数组
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isNumeric(char* str) {
        bool e = false;
        bool dot = false;
        int  eindex = INT_MAX;
        for (int i =0;str[i] != '\0';++i) {
            if (isNum(str[i]))
                continue;
            else if (str[i] == '+' && i == 0)
                continue;
            else if (str[i] == '+' && isE(str[i-1]) && isNum(str[i+1]))
                continue;
            else if (str[i] == '-' && i == 0)
                continue;
            else if (str[i] == '-' && isE(str[i-1]) && isNum(str[i+1]))
                continue;
            else if (isE(str[i]) && i != 0 && isNum(str[i-1]) && !e) {
                eindex = i;
                e = true;
                continue;
            }
            else if (str[i] == '.' && i != 0 && (isNum(str[i-1]) || isSign(str[i-1])) && isNum(str[i+1]) && !dot && i < eindex) {
                dot = true;
                continue;
            }
            else
                return false;
        }
        return true;
    }
    bool isSign(char c) {
        return c == '+' || c == '-';
    }
    bool isE(char c) {
        return c == 'E' || c == 'e';
    }
    bool isNum(char c) {
        int num = c-'0';
        return num >=0 && num <=9;
    }
};


 int main(int argc, char *argv[]) {
    Solution s;
    char arr[]="12e+6.4";
    cout << s.isNumeric(arr);
}

