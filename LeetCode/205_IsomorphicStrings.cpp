/* Given two strings s and t, determine if they are isomorphic.
* Two strings are isomorphic if the characters in s can be replaced to get t.
* All occurrences of a character must be replaced with another character
* while preserving the order of characters. No two characters may map to the
* same character but a character may map to itself.
* For example,
* Given "egg", "add", return true.
* Given "foo", "bar", return false.
* Given "paper", "title", return true.
* Note:
* You may assume both s and t have the same length.
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
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, int> smap, tmap;
		auto sz = s.size();
		for (decltype(sz) i = 0; i < sz; ++i) {
			if (smap[s[i]] != tmap[t[i]])
				return false;
			if (smap[s[i]] > 0 && (s.find(s[i]) != t.find(t[i])))
				return false;
			++smap[s[i]];
			++tmap[t[i]];
		}
		return true;
	}
	//12ms, Use array instead of Map;
	bool isIsomorphic1(string s, string t) {
		char smap[255] = { 0 }, tmap[255] = { 0 };
		auto sz = s.size();
		for (decltype(sz) i = 0; i < sz; ++i) {
			if (smap[s[i]] != tmap[t[i]])
				return false;
			if (smap[s[i]] > 0 && (s.find(s[i]) != t.find(t[i])))
				return false;
			++smap[s[i]];
			++tmap[t[i]];
		}
		return true;
	}
	//antoher really briliant way;
	bool isIsomorphic2(string s, string t) {
		char smap[255] = { 0 }, tmap[255] = { 0 };
		auto sz = s.size();
		for (decltype(sz) i = 0; i < sz; ++i) {
			if (smap[s[i]] != tmap[t[i]])
				return false;
			smap[s[i]] = i+1;
			tmap[t[i]] = i+1;
			//must add a non-negative number, because default key-value is 0.
			//use a i-relative number to record the position.
		}
		return true; 
	}
};
int main()
{

	system("pause");
	return 0;
}