/* You are a product manager and currently leading a team to develop a new product. 
 * Unfortunately, the latest version of your product fails the quality check. 
 * Since each version is developed based on the previous version, 
 * all the versions after a bad version are also bad.

 * Suppose you have n versions [1, 2, ..., n] and you want to find out the 
 * first bad one, which causes all the following ones to be bad.

 * You are given an API bool isBadVersion(version) which will return whether 
 * version is bad. Implement a function to find the first bad version. 
 * You should minimize the number of calls to the API.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <sstream>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		long long start = 1;
		long long end = (long long)n;
		//use long long is necessary,otherwise overflow happens.
		while (true) {
			long long mid = (start + end) / 2;
			bool flag = isBadVersion((int)mid);
			if (flag && !isBadVersion((int)mid - 1))
				return mid;
			else if (flag) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	int firstBadVersion1(int n) {
		int start = 1;
		int end = n;
		while (true) {
			//really smart way to avoid overflow
			int mid = start + (end-start) / 2;
			bool flag = isBadVersion(mid);
			if (flag && !isBadVersion(mid - 1))
				return mid;
			else if (flag) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
};

int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}