/* Given two strings s and t, write a function to determine if t is an anagram of s.

 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.

 * Note:
 * You may assume the string contains only lowercase alphabets. 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	//used map
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		}
		unordered_map<char, int> hashmap;
		for (auto i : s) {
			/*if (hashmap.find(i) == hashmap.end()) {
				hashmap[i] = 1;
			}
			else {
				++hashmap[i];
			}*/
			++hashmap[i];
		}
		for (auto i : t) {
			if (hashmap.find(i) == hashmap.end() || hashmap[i] <= 0) {
				return false;
			}
			--hashmap[i];
		}
		return true;
	}
	// array is more fast than unorderd_multimap . About 12ms
	bool isAnagram1(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		}
		int count[26] = { 0 };
		for (int i = 0; i < s.length(); ++i) {
			count[s[i] - 'a']++;
			count[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; ++i) {
			if (count[i])
				return false;
		}
		return true;
	}
	//sort and compare
	bool isAnagram2(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
};
int main()
{
	Solution s = Solution();
	string a("accc");
	string b("acca");
	cout << (s.isAnagram1(a, b) ? "true" : "false") << endl;


	system("pause");
	return 0;
}