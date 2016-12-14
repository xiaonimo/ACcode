/* Title:
 * 约瑟夫环问题
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m){
        if (n < 1 || m<1)
            return -1;
        if (n == 1)
            return 0;
        return (LastRemaining_Solution(n-1, m)+m)%n;
    }
    int LastRemaining_Solution1(int n, int m){
        if (n < 1 || m<1)
            return -1;
        int last = 0;
        for (int i = 2;i<=n;++i)
            last = (last+m)%i;
        return last;
    }
};


 int main(int argc, char *argv[]) {



    return 0;
}

