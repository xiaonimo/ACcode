/* Title:
 * Find the nth digit of the infinite integer sequence 
 * 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
 * Note:
 * n is positive and will fit within the range of a 
 * 32-bit signed integer (n < 2^31).

 * Example 1:
 * Input:3
 * Output:3
 * Example 2:
 * Input:11
 * Output:0

 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
 * ... is a 0, which is part of the number 10.
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>

using namespace std;

class Solution {
public:
	//TLE
	int findNthDigit(int n) {
		int num = 0;
		int dit = 0;
		while (dit < n) {
			++num;
			if (num < 10)
				dit += 1;
			else if (num < 100)
				dit += 2;
			else if (num < 1000)
				dit += 3;
			else if (num < 10000)
				dit += 4;
			else if (num < 100000)
				dit += 5;
			else if (num < 1000000)
				dit += 6;
			else if (num < 10000000)
				dit += 7;
			else if (num < 100000000)
				dit += 8;
			else
				dit += 9;
		}
		while (dit>n) {
			num /= 10;
			--dit;
		}
		return num % 10;
	}
	//really bullshit,suck!!!!
	int findNthDigit1(int n) {
		long long pre_dit = 0, cur_dit = 0, num_dit = 0;
		while (n > cur_dit) {
			++num_dit;
			pre_dit = cur_dit;
			cur_dit += 9 * num_dit * (int)pow(10, num_dit - 1);
		}
		int num = (int)pow(10, num_dit - 1) + (n - pre_dit) / num_dit - 1;
		int dit = (n - pre_dit) % num_dit;
		if (dit == 0) return num % 10;
		++num;
		while (num_dit - dit) {
			num /= 10;
			++dit;
		}
		return num % 10;
	}
};

int main(){
	Solution s;
	cout << s.findNthDigit1(1000000000);
	system("pause");
	return 0;
}
