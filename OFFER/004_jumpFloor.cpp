/**Title:
 * 1. 跳台阶问题：n级台阶。一只青蛙可以一次跳1级，也可以一次跳2级，那么n级台阶可以有多少跳法?
 * 2. 变态跳台阶：n级台阶。一只青蛙一次可以跳1~n任意级，那么n级台阶有多少种跳法？
 * 3. 矩形覆盖问题： 一个大矩形2*n，使用一个小矩形2*1去完全不重叠，不超出的覆盖，有多少种覆盖方案？
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
	/* 设到达n节台阶有f(n)种方式，到达第n节台阶有两种方式，
	 * 从n-1级跳1节上去，从n-2节直接跳两节上去,这里只有这一种跳法
	 * 不能是一级一级的跳，因为在f(n-1)中已经包含了
	 * 所以，f(n) = f(n-1) + f(n-2);
	 */
	int jumpFloor1(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		int f1 = 1, f2 = 2;
		int i = 1;
		while (i < n) {
			f2 += f1;
			f1 = f2 - f1;
			++i;
		}
		return f2;
	}

	/* 设到达n级台阶有f(n)种方式。到达n级台阶的方式有
	 * f(n-1), 最后一次跳一级
	 * f(n-2), 最后一次跳两级
	 * f(n-k), 最后一次跳k级
	 * 所以，f(n) = f(n-1)+f(n-2)+...+f(1);
	 * 现在看一下等式，对任意的f(k)= f(k-1) +...+ f(1);
	 * f(k+1) = f(k)+f(k-1) + .. f(1) = 2f(k);
	 */
	int jumpFloor2(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		return pow(2, n - 1);
	}
	/* 3. 矩形覆盖问题的原理和代码和jumpFloor1一样*/
};

int main(void)
{
	

	system("pause");
}
