#include<iostream>  

using namespace std;
class Solution
{
public:
	int _power(int x, int n) {
		if (n == 0) return 1;
		while ((n & 1) == 0) {
			x = x*x;
			n >>= 1;
		}
		int res = x;
		n >>= 1;
		while (n != 0) {
			x = x*x;
			if ((n & 1) != 0)
				res *= x;
			n >>= 1;
		}
		return res;
	}
};
int main(void)
{
	Solution s;
	cout << s._power(10, 3);
	system("pause");
	return 0;
}
