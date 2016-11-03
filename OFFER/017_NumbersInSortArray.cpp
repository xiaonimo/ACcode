/* Title:
 * 统计一个数字在排序数组（从小到大排序）中出现的次数。
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //先找到这个数，然后向前向后查找相同的元素
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.empty()) return 0;
        int l = 0, r = data.size()-1,m = l+(r-l)/2;
        while (l<r) {
            m = l+(r-l)/2;
            if (k == data[m])
                break;
            else if (k < data[m])
                r = m-1;
            else
                l = m+1;
        }

        if (k != data[m])
            return 0;

        int cnt = 1;
        int i = m-1;
        while (k == data[i]) {
            ++cnt;
            --i;
        }
        i = m+1;
        while (k == data[i]) {
            ++cnt;
            ++i;
        }
        return cnt;
    }
    //找到这个数的第一个下标和最后一个下标，做差+1
    int GetNumberOfK1(vector<int> data ,int k) {
        if (data.empty()) return 0;
        int first = getFirstK(data, k);
        int last = getLastK(data,k);
        cout << first << endl << last <<endl;
        if (first == -1 || last == -1)
            return 0;
        return last-first+1;
    }
    int getFirstK(vector<int> data, int k) {
        int l = 0,r=data.size()-1,m=l+(r-l)/2;
        while (l<r) {
            m = l+(r-l)/2;
            if (k == data[m]){
                if (m == l || data[m-1]!=k)
                    return m;
                else
                    r -= 1;
            }
            else if (k < data[m]) {
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        return k == data[l]?l:-1;
    }
    int getLastK(vector<int> data, int k) {
        int l = 0,r=data.size()-1,m=l+(r-l)/2;
        while (l<r) {
            m = l+(r-l)/2;
            if (k == data[m]){
                if (m == r || data[m+1]!=k)
                    return m;
                else
                    r += 1;
            }
            else if (k < data[m]) {
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        return k == data[l]?l:-1;
    }
};

int main(int argc, char *argv[]) {

    Solution s;
    cout << s.GetNumberOfK1(vector<int>{3}, 3);
    return 0;
}
