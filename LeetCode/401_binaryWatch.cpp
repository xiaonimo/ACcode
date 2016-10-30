/* Title:
 * Binary watch:n bits and m "1",
 * hao many numbers can be done;
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>

using namespace std;
class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> res;
		for (int i = 0; i <= 4 && i <= num; ++i) {
			if (num - i > 6) continue;
			vector<int> hour, min;
			int binary_num = 0;
			readBinaryNum(4, i, binary_num, hour);
			readBinaryNum(6, num - i, binary_num, min);
			for (auto h : hour) {
				if (h >= 12) continue;
				for (auto m : min) {
					if (m >= 60) continue;
					res.push_back((h ? to_string(h) : "0") + (m > 9 ? ":" : ":0")
						+ (m ? to_string(m) : "0"));
				}
			}
		}
		return res;
	}
	//bits表示二进制数的位数，ones表示1的个数，num是构造的二进制数
	//使用递归的方式，很简洁。
	void readBinaryNum(int bits, int ones, int num, vector<int> &ans) {
		if (ones == 0) {
			ans.push_back(num);
			return;
		}
		if (bits == 0)
			return;
		for (int i = 0; i < bits; ++i) {
			readBinaryNum(i, ones - 1, num | (1 << i), ans);
		}
	}
	//其实，做这题最简单的方法是使用c++中的bitset类。
	//来自leetcode 的方法：
	vector<string> readBinaryWatch1(int num) {
		vector<string> res;
		for (int h = 0; h < 12; ++h) {
			for (int m = 0; m < 60; ++m) {
				if (bitset<10>((h << 6) + m).count() == num)
					res.push_back(to_string(h) + (m>9 ? ":" : ":0") + to_string(m));
			}
		}
		return res;
	}
	//归纳到一个问题，给出二进数位数bits,1的个数bits,
	//给出所有的可能的二进制数。
	vector<int> readBinaryNum1(int bits, int ones) {
		vector<int> res;
		int small_num = pow(2, ones) - 1;
		int big_num = small_num << (bits - ones);
		for (int i = small_num; i <= big_num; ++i) {
			//但是这里存在magic number
			if (bitset<32>(i).count() == ones)
				res.push_back(i);
		}
		return res;
	}
};

int main(){
	Solution s;
	vector<int> vec = s.readBinaryNum1(6,4);
	for (auto s : vec)
		cout << s << endl;
	system("pause");
	return 0;
}
