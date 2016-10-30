/* Given an arbitrary ransom note string and another string containing letters from all 
 * the magazines, write a function that will return true if the ransom  note can be 
 * constructed from the magazines ; otherwise, it will return false. 
 * Each letter in the magazine string can only be used once in your ransom note.

 * Note:
 * You may assume that both strings contain only lowercase letters.

 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
	//32ms
	bool canConstruct0(string ransomNote, string magazine) {
		int direct[256] = { 0 };
		for (auto i : magazine) {
			++direct[i];
		}
		for (auto i : ransomNote) {
			if (--direct[i] < 0)
				return false;
		}
		return true;
	}
	//28ms
	bool canConstruct1(string ransomNote, string magazine) {
		for (auto i : ransomNote) {
			auto pos = magazine.find(i);
			if (pos == string::npos) {
				return false;
			}
			magazine.erase(pos, 1);
		}
		return true;
	}
};
int main()
{
	Solution s = Solution();
	string s1 = "aa";
	string s2 = "aabv";
	cout << (s.canConstruct1(s1, s2) ? "true" : "false") << endl;
	system("pause");
	return 0;
}