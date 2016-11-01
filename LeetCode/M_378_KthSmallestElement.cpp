/* Title:
 * Given a n x n matrix where each of the rows
 * and columns are sorted in ascending order,
 * find the kth smallest element in the matrix.
 * Note that it is the kth smallest element in
 * the sorted order, not the kth distinct element.

 * Example:
 * matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
 * ],
 * k = 8,
 * return 13.

 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <hash_set>

using namespace std;

class Solution {
public:
    //nlogn*N;N is the scan space from the min from the max
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0],r = matrix[n-1][n-1],m;
        while (l<r) {
            m = l+(r-l)/2;
            int cnt = 0;//number of element no bigger than m
            for (int i = 0;i<n;++i) {
                int pos = upper_bound(begin(matrix[i]),end(matrix[i]),m)
                    -begin(matrix[i]);
                cnt += pos;
            }
            if (cnt < k)
                l = m+1;
            else
                r = m;
        }
        return l;
    }
};

int main(int argc, char *argv[]) {




    return 0;
}
