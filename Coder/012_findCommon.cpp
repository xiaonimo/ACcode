#include <iostream>
#include <string>
using namespace std;


class LCA {
public:
	int getLCA1(int a, int b) {
		// write code here
		if (a>b) swap(a, b);
		int ta = a, tb = b;
		while (ta != 1) {
			tb = b;
			while (tb >= ta) {
				if (ta == tb)
					return ta;
				tb /= 2;
			}
			ta /= 2;
		}
		return ta;
	}

	int getLCA2(int a, int b) {
		while (a != b) {
			if (a > b) a >>= 1;
			if (a < b) b >>= 1;
		}
		return a;
	}
	int getLCA3(int a, int b) {
		string sa = _int2b(a);
		string sb = _int2b(b);
		int res = 0;
		for (unsigned i = 0; i < sa.size() && i < sb.size(); ++i) {
			if (sa[i] != sb[i])
				break;
			res = (res << 1) + sa[i] - '0';
		}
		return res;
	}
	string _int2b(int x) {
		string res;
		while (x) {
			res = char((x & 1) + '0') + res;
			x >>= 1;
		}
		return res;
	}
};

int main() {

	return 0;
}