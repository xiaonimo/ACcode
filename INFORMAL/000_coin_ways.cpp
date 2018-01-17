#include <iostream>
#include <vector>

using namespace std;

/*
 * 有四种硬币若干，1,5,10,25，求组成n元硬币有多少种方法
 */
class Coins {
public:
    int countWays(int n) {
        // write code here
        vector<int> dp(n+1, 0);
        vector<int> coin{1,5,10,25};
        dp[0] =1;
        for (int i = 0;i<4;++i) {
            for (int j = coin[i];j<=n;++j)
                dp[j] += dp[j-coin[i]]%1000000007;
        }
        return dp[n]%1000000007;
    }
};
