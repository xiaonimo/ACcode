/* title
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]

 * 最先考虑到的就是处理0，把所有的零删除，记录删除的0的个数，然后push_back添加
 * 第二种考虑的是处理非零数，把非零数和前面的第一个0互换位置，遍历一次之后，就可以完成题目要求
 * 第三种最简单的方法是把所有非零数按照顺序从vector开头开始存储。最后添加0
 */

void moveZeroes(vector<int>& nums) {
		int cnt_zeros = 0;
		for (int i = 0, n = nums.size(); i < n; ++i) {
			//记录下一个非零数之前0的个数
			if (nums[i] == 0) {
				++cnt_zeros;
			}
			if (nums[i] != 0 && cnt_zeros) {
				swap(nums[i-cnt_zeros], nums[i]);
				//记录0个数的变量归零
				cnt_zeros == 0;
			}
		}
	
void moveZeros2(vector<int>& nums) {
		int cnt_zeros = 0;
		int i = 0;
		while (i < (nums.size()-cnt_zeros)) {
			if (nums[i] == 0) {
				nums.erase(nums.begin() + i);
				nums.push_back(0);
				++cnt_zeros;
			}
			else {
				//这里一定要注意，只有是非零的时候，下标才加1，
				//否则连续两个0的情况不能检测。
				++i;
			}
		}
	}
	
	
void moveZeros3(vector<int>& nums) {
		int i = 0, j = 0;
		for (; i<nums.size(); ++i) {
			if (nums[i] != 0) {
				//非零数按顺序存入vector
				swap(nums[j++], nums[i]);
			}
		}
		for (; j < nums.size(); ++j) {
			//末尾补充零
			nums[j] = 0;
		}

	}
	
