/* 题目：
 * 同时找出数组中的最大数和最小数
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
#include<cassert>

using namespace std;
typedef pair<int, int> twoInt;
class Solution {
public:
	//方法1：遍历一次，数组，需要比较2*Ｎ次
	twoInt findMaxMin(vector<int> nums);
	//方法2：每次选择相邻的两个数，比较两个数的大小，
	//小的与minNum比较，大的与maxNum比较。比较次数是1.5*N
	twoInt findMaxMin1(vector<int> nums);
};

twoInt Solution::findMaxMin(vector<int> nums) {
	assert(nums.size() >= 1);
	int maxNum = nums[0], minNum = nums[0];
	for (auto num : nums) {
		if (num < minNum) minNum = num;
		if (num > maxNum) maxNum = num;
	}
	return{ minNum, maxNum };
}
twoInt Solution::findMaxMin1(vector<int> nums) {
	assert(nums.size() >= 1);
	int maxNum = nums[0], minNum = nums[0];
	for (int i = 2; i < nums.size(); i+=2) {
		if (nums[i] < nums[i - 1]) {
			if (nums[i] < minNum) minNum = nums[i];
			if (nums[i - 1] > maxNum) maxNum = nums[i];
		}
		else {
			if (nums[i] > maxNum) maxNum = nums[i];
			if (nums[i - 1] < minNum) minNum = nums[i - 1];
		}
	}
	if (nums[nums.size() - 1] > maxNum) maxNum = nums[nums.size() - 1];
	if (nums[nums.size() - 1] < minNum) minNum = nums[nums.size() - 1];
	return{ minNum, maxNum };
}
int main(){
	Solution s;
	vector<int> vec{ 1, 23, -1, 4, 5, 8, 9, 4, 56, 5 };
	vector<int> vec1;
	cout << s.findMaxMin1(vec).first << "\t" << s.findMaxMin1(vec).second;
	system("pause");
	return 0;
}
