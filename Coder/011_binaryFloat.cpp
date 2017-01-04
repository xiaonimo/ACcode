/* Title:
* cat and dog
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class BinInsert {
public:
	string printBin(double num) {
		// write code here
		double ope = 0.5;
		string res("0.");
		bool small = true;
		while (1) {
			if (num > ope) {
				small = false;
				res += string("1");
				num -= 1.0 / ope;
				ope /= 2.0;
			}
			else if (num == (1.0 / ope)) {
				res += string("1");
				break;
			}
			else if (num < (1.0 / ope) && small){
				ope /= 2.0;
				res += string("0");
			}
			else {
				return string("Error");
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	BinInsert s;
	for (auto c : s.printBin(0.255))
		cout << c;
	system("pause");
	return 0;
}

