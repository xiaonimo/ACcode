/* Title:
 * 长度为N的整数数组，求其中N-1个元素的最大值乘积值
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
	/*
	 *想法1：遍历求出每个N-1元素的乘积，复杂度O(N^2)
	 *想法2：求出N个元素的乘积P
	 *      P == 0，找到第一个为0的数，计算其余N-1个数的乘积，和0比较，取最大值
	        P > 0,找到最小的正整数，P除以该数就是所求，如果没有整数，那就找出绝对值最大的负数，相除。
			P < 0,找到最大的负数（绝对值最小），除以该负数就是所求
			风险：乘积P容易造成溢出。
	 *方法1：为了规避上述方法中的溢出风险，我们统计数组正负、0元素的个数，判断N个元素乘积结果的正负还是0；
	 */
	int multiplyValue(vector<int> nums) {
		assert(nums.size() >= 2);
		int negs = 0, zeros = 0;
		int res = 1;
		//统计负数和0的个数
		for (auto num : nums) {
			if (num == 0) ++zeros;
			if (num < 0) ++negs;
		}
		//如果有2个以上的0，那么结果就是0
		if (zeros >= 2) return 0;
		//如果有一个0，就计算除了0之外的元素乘积
		if (zeros == 1) {
			for (auto num : nums){
				if (num != 0) res *= num;
			}
			return res;
		}
		//计算所有元素的乘积
		for (auto num : nums)
			res *= num;
		//如果所有的元素乘积大于0
		if (res > 0) {
			int min_posi = 0, min_neg = 0;
			for (auto num : nums) {
				if (num > min_posi) min_posi = num;
				if (num < min_neg) min_neg = num;
			}
			return (min_posi != 0)?res / min_posi:res/min_neg;
		}
		int max_neg = INT_MIN;
		for (auto num : nums) {
			if (num <0 && num>max_neg) max_neg = num;
		}
		return res / max_neg;
	}
};


int main(void)
{
	int i = 0;
	cout << sizeof(char[2]) << endl;
	cout << sizeof(char &) << endl;
	system("pause");
	return 0;
}
