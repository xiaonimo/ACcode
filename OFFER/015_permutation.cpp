/* Title:
 * Write a program that outputs the string representation
 * of numbers from 1 to n.
 * But for multiples of three it should output “Fizz”
 * instead of the number and for the multiples of
 * five output “Buzz”. For numbers which are multiples
 * of both three and five output “FizzBuzz”.

 * Example:
 * n = 15,
 * Return:
 * [
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
 * ]
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    //简单的permutation。
    //默认s是非空,first last参数合法
    vector<string> permutation(string s, int first, int last) {
        vector<string> res;
        if (s.empty() || first > last) return res;
        if (first == last) {
            res.push_back(string(1, s[first]));
            return res;
        }
        for (int i = first; i <= last; ++i) {
            //这个语句是去重复的作用
            if (i != first && (s[i] == s[i-1] || s[i] == s[first]))
                continue;
            swap(s[first], s[i]);
            vector<string> subres = permutation(s, first+1, last);
            for (auto str:subres)
                res.push_back(s[first]+str);
            swap(s[first],s[i]);
        }
        return res;
    }
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.empty()) return res;
        sort(begin(str), end(str));
        res = permutation(str, 0, str.size()-1);

        sort(begin(res), end(res));
        return res;
    }


};

int main(int argc, char *argv[]) {
    Solution s;
    string str = "aabc";
    vector<string> vec = s.Permutation(str);
    for (auto str:vec)
        cout << str <<endl;
    cout << vec.size()<<endl;
    return 0;
}
