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
    int GetUglyNumber_Solution(int index) {
        vector<int> ugly(1,1);
        int ugly2 = 0, ugly3 = 0, ugly5 = 0;

        for (int i = 1; i <= index; ++i) {
            ugly.push_back(min(ugly[ugly2]*2, min(ugly[ugly3]*3, ugly[ugly5]*5)));

            while (ugly[ugly2] * 2 <= ugly[i])
                ++ugly2;
            while (ugly[ugly3] * 3 <= ugly[i])
                ++ugly3;
            while (ugly[ugly5] * 5 <= ugly[i])
                ++ugly5;
        }
        return ugly[index-1];
    }
};

int main(int argc, char *argv[]) {
    Solution s1;
    for (int i = 1;i<10;++i)
        cout << s1.GetUglyNumber_Solution(i);

}
