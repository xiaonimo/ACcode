/* Title:
 * 字符串翻转
 */

#include <iostream>
#include <string>
using namespace std;

class ReverseEqual {
public:
	bool checkReverseEqual(string s1, string s2) {
		// write code here
		if (s1.size() != s2.size())
			return false;
		/*
		for (unsigned i = 0;i<s2.size();++i) {
		int m = i, n = 0;
		while (n < s1.size() && s2[m] == s1[n]) {
		m = (m+1)%s2.size();
		++n;
		}
		if (n == s1.size())
		return true;
		}
		return false;
		*/
		s1 += s1;
		return s1.find(s2) != string::npos;
	}
};
 int main(int argc, char *argv[]) {
    
}

