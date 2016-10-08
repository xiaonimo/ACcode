/*
 *2.6精确表示小数
 *2.7最大公约数
 */
#include <iostream>
using namespace std;

class Solution {
public:
	pair<long long, long long> float2fraction(long long doub, long long int circle);
	long long gcd1(long long x, long long y);
	long long gcd2(long long x, long long y);
	long long gcd3(long long x, long long y);
};
/*方法1：
 *f(x, y) = f(y, x%y);
 */
long long Solution::gcd1(long long x, long long y) {
	return !y ? x : gcd1(y, x%y);
}
/*方法2：
 *f(x, y) = f(x-y, y)(前提是x>y)
 */
long long Solution::gcd2(long long x, long long y) {
	if (!y)
		return x;
	return x >= y ? gcd2(x - y, y) : gcd2(y, x);
}
/*方法3：
 *如果x=k*x1,y=k*y1,那么，f(x, y) = k*f(x1, y1);
 *如果p是素数，x=p*x1,y%p!=0,那么,f(x ,y) = f(x/p, y)
 *在下面的代码中，统一使用2代表k和p，因为乘2除2的操作可以
 *转换成移位操作，效率高。
 */
long long Solution::gcd3(long long x, long long y) {
	if (x < y) return gcd3(y, x);
 	if (!y) return x;
	if ((x & 1) == 0 && (y & 1) == 0)
		return (gcd3(x >> 1, y >> 1) << 1);
	else if ((x & 1) == 0)
		return gcd3(x >> 1, y);
	else if ((y & 1) == 0)
		return gcd3(x, y >> 1);
	else
		return gcd3(x - y, y);
}
/*获取一个整数的位数*/
int getDit(long long x) {
	int cnt = 0;
	while (x) {
		++cnt;
		x /= 10;
	}
	return cnt;
}
/*能够用分数表示的小数分别是有限小数和无限循环小数
 *有限小数：
 *假如该小数是0.abcdefg,那么分子就是abcdefg,分母是10^7
 *无限循环小数：
 *假如该小数是X = 0.abcdefg(efg),efg是循环的部分
 *10^7 * X = abcdefg.efg
 *X = abcdefg/10^7 + 0.efg/10^7
 *Y = 0.efg
 *10^3 * Y = efg.efg
 *(10^3-1)*Y = efg;
 *Y = efg/(10^3 - 1)
 *然后两个分数进行通分
 */
pair<long long, long long > Solution::float2fraction(long long doub, long long circle) {
	long long num = 0;
	long long den = 0;
	long long gcd = 0;
	if (doub == 0) return{ num, den };
	
	int numDit = 0, cirDit =0;
	numDit = getDit(doub);
	cirDit = getDit(circle);

	if (circle == 0) {
		num = doub;
		den = pow(10, numDit);
	}
	else {
		num = doub*(pow(10, cirDit) - 1) + circle;
		den = pow(10, numDit)*(pow(10, cirDit) - 1);
	}
	gcd = gcd3(num, den);
	return{ num / gcd, den / gcd };
}

int main() {
	Solution s = Solution();
	pair<int, int> res = s.float2fraction(13333, 3);
	cout << res.first << "/" << res.second << endl;
	system("pause");
	return 0;
}