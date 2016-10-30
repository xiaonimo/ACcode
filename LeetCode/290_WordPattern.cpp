/* Given a pattern and a string str, find if str follows the same pattern.
 * Here follow means a full match, such that there is a bijection between 
 * a letter in pattern and a non-empty word in str.

 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * You may assume pattern contains only lowercase letters, 
 * and str contains lowercase letters separated by a single space.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <sstream>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int arr[26] = { 0 };
		unordered_map<string, int> hstr;
		string part;
		int cur1=0, cur2=-1;
		int psz = pattern.size();
		int ssz = str.size();
		for (int i = 0; i < psz; ++i) {
			++cur2;
			cur1 = cur2;
			if (cur2 >= ssz)
				return false;
			while (cur2 < ssz && str[cur2] != ' ')
				++cur2;
			string word(begin(str) + cur1, begin(str) + cur2);
			if (arr[pattern[i]-'a'] != hstr[word])
				return false;
			arr[pattern[i]-'a'] = i + 1;
			hstr[word] = i + 1;
		}
		return cur2 == ssz;
	}
	//using istringstream
	bool wordPattern1(string pattern, string str) {
		int arr[26] = { 0 };
		unordered_map<string, int> hstr;
		istringstream ss(str);
		int i = 0;
		int psz = pattern.size();
		string word;
		for (; ss >> word; ++i) {
			if (i == psz || arr[pattern[i] - 'a'] != hstr[word])
				return false;
			arr[pattern[i] - 'a'] = hstr[word] = i + 1;
		}
		return i == psz;

	}
};

int main()
{
	Solution s = Solution();
	
	cout <<(s.wordPattern("abba", "dog cat cat dog")?"true":"false");
	system("pause");
	return 0;
}