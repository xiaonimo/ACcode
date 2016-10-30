/* Write a function that takes a string as input and reverse only 
 * the vowels of a string.

 * Example 1:
 * Given s = "hello", return "holle".

 * Example 2:
 * Given s = "leetcode", return "leotcede".

 * Note:
 * The vowels does not include the letter "y".
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
	//44ms.
	string reverseVowels(string s) {
		if (s.empty()) {
			return s;
		}
		stack<char> vowels;
		set<char> VOW = {'a', 'A', 'e','E','i','I','o','O','u','U'};
		for (auto &i : s) {
			if (VOW.find(i) != VOW.end()) {
				vowels.push(i);
				i = 'a';
			}
		}
		for (auto &i : s) {
			if (i == 'a') {
				i = vowels.top();
				vowels.pop();
			}
		}
		return s;
	}
	//24ms.
	string reverseVowels1(string s) {
		if (s.empty()) {
			return s;
		}
		for (int i = 0, j = s.size() - 1; i < j;++i,--j) {
			while (i < j && s[i] != 'a'&&s[i] != 'A'
				&&s[i] != 'e'&&s[i] != 'E'&&s[i] != 'i'&&s[i] != 'I'
				&&s[i] != 'o'&&s[i] != 'O'&&s[i] != 'u'&&s[i] != 'U') {
				++i;
			}
			while (i < j && s[j] != 'a'&&s[j] != 'A'
				&&s[j] != 'e'&&s[j] != 'E'&&s[j] != 'i'&&s[j] != 'I'
				&&s[j] != 'o'&&s[j] != 'O'&&s[j] != 'u'&&s[j] != 'U') {
				--j;
			}
			swap(s[i], s[j]);
		}
		return s;
	}
	//12ms,use array to determine it's the vowels or not.
	string reverseVowels(string s) {
		int dict[256] = { 0 };
		dict['a'] = 1, dict['A'] = 1;
		dict['e'] = 1, dict['E'] = 1;
		dict['i'] = 1, dict['I'] = 1;
		dict['o'] = 1, dict['O'] = 1;
		dict['u'] = 1, dict['U'] = 1;
		int start = 0, end = (int)s.size() - 1;
		while (start < end){
			while (start < end && dict[s[start]] == 0) start++;
			while (start < end && dict[s[end]] == 0) end--;
			swap(s[start], s[end]);
			start++; end--;
		}
		return s;
	}
};
int main()
{
	Solution s = Solution();
	string str = "leetcode";
	cout << s.reverseVowels1(str);
	system("pause");
	return 0;
}