#include <iostream>
#include <vector>

using namespace std;

/*
 * 有若干1元，3元，5元硬币val数组表示。求使用最少硬币数满足n
 */
int find_coin(vector<int> val, int n) {
    vector<int> arr(n+1, 0x01111111);
    arr[0] = 0;
    for (int i = 1;i<=n;++i) {
        for (auto v:val) {
            if (v>i) continue;
            if (arr[i] > arr[i-v]+1)
                arr[i] = arr[i-v]+1;
        }
    }
    return arr[n];
}

/*
 * 求最长非递减子数组
 */
int find_arr(vector<int> arr) {
    //dp[i]数组表示包含i元素的情况下，最长递增子数组
    vector<int> dp(arr.size()+1, 1);
    int len = 0;
    for (int i = 1;i<=(int)arr.size(); ++i) {
        int max_len = 1;
        for (int j = 0; j<i; ++j) {
            if (arr[j] <= arr[i] && dp[j]+1>dp[i])
                max_len = dp[j]+1;
        }
        dp[i] = max_len;
        if (dp[i] > len)
            len = dp[i];
    }

    int res = len;
    for (int i =arr.size();i>=0;--i) {
        if (dp[i] == len) {
            cout << arr[i] <<" ";
            len--;
        }
    }
    return res;
}

int main() {
    cout << endl << find_arr(vector<int>{3,2,1,2,3,5,4,7,8,9,5});

    return 0;
}
