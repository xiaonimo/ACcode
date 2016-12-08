/* Title:
 * 判断一棵树是不是另一棵树的子树
 */

#include <iostream>
#include <vector>
#include <stdio.h>
#include <windows.h>
using namespace std;

class Solution {
public:
    static bool cmp(int a,int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A<B;
    }
    string PrintMinNumber(vector<int> numbers) {
        string  answer="";
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i=0;i<numbers.size();i++){
            answer+=to_string(numbers[i]);
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution s1;

}
