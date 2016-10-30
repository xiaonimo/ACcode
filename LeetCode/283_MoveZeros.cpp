/* title
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]

 * ���ȿ��ǵ��ľ��Ǵ���0�������е���ɾ������¼ɾ����0�ĸ�����Ȼ��push_back���
 * �ڶ��ֿ��ǵ��Ǵ�����������ѷ�������ǰ��ĵ�һ��0����λ�ã�����һ��֮�󣬾Ϳ��������ĿҪ��
 * ��������򵥵ķ����ǰ����з���������˳���vector��ͷ��ʼ�洢��������0
 */

void moveZeroes(vector<int>& nums) {
		int cnt_zeros = 0;
		for (int i = 0, n = nums.size(); i < n; ++i) {
			//��¼��һ��������֮ǰ0�ĸ���
			if (nums[i] == 0) {
				++cnt_zeros;
			}
			if (nums[i] != 0 && cnt_zeros) {
				swap(nums[i-cnt_zeros], nums[i]);
				//��¼0�����ı�������
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
				//����һ��Ҫע�⣬ֻ���Ƿ����ʱ���±�ż�1��
				//������������0��������ܼ�⡣
				++i;
			}
		}
	}
	
	
void moveZeros3(vector<int>& nums) {
		int i = 0, j = 0;
		for (; i<nums.size(); ++i) {
			if (nums[i] != 0) {
				//��������˳�����vector
				swap(nums[j++], nums[i]);
			}
		}
		for (; j < nums.size(); ++j) {
			//ĩβ������
			nums[j] = 0;
		}

	}
	
