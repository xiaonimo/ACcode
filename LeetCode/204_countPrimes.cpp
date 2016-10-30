/* Count the number of prime numbers less than a non-negative number, n.
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
class Solution {
public:
	int countPrimes(int n) {
		vector<bool> isPrime(n, true);
		for (int i = 2; i * i < n; i++) {
			if (!isPrime[i])
				continue;
			for (int j = i * i; j < n; j += i) {
				isPrime[j] = false;
			}
		}
		int count = 0;
		for (int i = 2; i < n; ++i) {
			if (isPrime[i])
				++count;
		}
		return count;
	}
	int countPrimes1(int n) {
		int count = 0;
		vector<bool> isPrime(n, true);
		for (long long i = 2; i < (long long)n; ++i) {// use longlong instead of int to avoid overflow
			if (!isPrime[i - 1])
				continue;
			++count;
			for (long long j = i * i; j < (long long)n; j += i) {
				isPrime[j - 1] = false;
			}
		}
		return count;
	}
};
int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}