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
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        string fizz("Fizz");
        string buzz("Buzz");
        string fizzbuzz("FizzBuzz");
        for (int i = 0;i<n;++i) {
            if ((i+1)%15 == 0)
                res[i] = fizzbuzz;
            else if ((i+1)%5 == 0)
                res[i] = buzz;
            else if ((i+1)%3 == 0)
                res[i] = fizz;
            else
            //to_string不被一些编译器支持
                res[i] = to_string(i+1);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
