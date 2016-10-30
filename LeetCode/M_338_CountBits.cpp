/* Title:
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num 
 * calculate the number of 1's in their binary representation and return them as an array.
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].

 * Follow up:
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
 * But can you do it in linear time O(n) /possibly in a single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function 
 * like __builtin_popcount in c++ or in any other language.
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
	//63ms
	vector<int> countBits(int num) {
		vector<int> res;
		for (int i = 0; i <= num; ++i) {
			res.push_back(bitset<32>(i).count());
		}
		return res;
	}
	//这题很明确使用Dp方法，但是却纠结于a[i]和a[i-1]之间的关系
	//实际上应该考虑的是a[x] = a[y] + 1这种关系。
	vector<int> countBits1(int num) {
		vector<int> res(num+1, 0);
		for (int i = 1; i <= num; ++i) {
			res[i] = res[i / 2] + res[i % 2];
		}
		return res;
	}
	vector<int> countBits2(int num) {
		vector<int> res(num + 1, 0);
		for (int i = 1; i <= num; ++i) {
			res[i] = res[i&(i-1)] + 1;
		}
		return res;
	}
};

int main(void)
{
	
	system("pause");
	return 0;
}
