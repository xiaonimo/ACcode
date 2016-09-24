/* Title:
 * 给定一个sum，在数组中找出两个元素a,b
 * 满足a + b = sum,给出下标。
 * 如果是三个数呢，a+b+c=sum.该怎么求？
 * 如果不存在解，求出最接近sum的三个数，
 * 该怎么办？
 * 给定一个数N和一组数字S，求S中最接近N
 * 的子集。NP，NP-complete问题。
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>

using namespace std;
typedef pair<int, int> twoInt;

class Solution {
public:
	//复杂度，O(N*logN).
	twoInt findSum(vector<int> nums, int sum) {
		sort(begin(nums), end(nums));
		int i = 0, j = nums.size()-1;
		while (i < j) {
			if (nums[i] + nums[j] == sum)
				return{ i, j };
			else if (nums[i] + nums[j] < sum)
				++i;
			else
				--j;
		}
		return{ -1, -1 };
	}
};

int main(){
	Solution s;
	
	system("pause");
	return 0;
}
