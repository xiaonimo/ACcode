/* Title:
 * 字符串翻转
 */

#include <iostream>
#include <string>
using namespace std;

class Reverse {
public:
	string reverseString(string iniString) {
		// write code here
		if (iniString.empty())
			return iniString;
		for (unsigned i = 0, j = iniString.size() - 1; i<j; ++i, --j) {
			iniString[i] ^= iniString[j] ^= iniString[i] ^= iniString[j];
		}
		return iniString;
	}
};
 int main(int argc, char *argv[]) {
    
}

