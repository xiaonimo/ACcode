/* Title:
 * Two sum,and the vector is sorted
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
#include<cassert>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> res(2, 0);
		int i = 0, j = numbers.size() - 1;
		while (i<j) {
			int sum = numbers[i] + numbers[j];
			if (sum == target) {
				res[0] = i + 1;
				res[1] = j + 1;
				break;
			}
			else if (sum > target)
				--j;
			else
				++i;
		}
		return res;
	}
};

int main(void)
{

	system("pause");
	return 0;
}
