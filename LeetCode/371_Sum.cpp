/* title
 * Calculate the sum of two integers a and b, 
 * but you are not allowed to use the operator + and -
 */
/* 这道题实际上考察的是计算机运算原理或者是二进制位操作的原理。
 * 首先，我们先看一个例子，十进制，4+1=5.然而在二进制中算式是：100+001=101，
 * 也就是十进制的5.在这种各个数位之间没有进位的情况下，a^b就是两者的和。
 * 如果有进位的话，十进制，2+6=8，二进制表达式是 010+110=1000.
 * 首先我们还是异或一下，010^110=100,但是这样算是没有进位的。
 * 现在算一下进位，进位的话 就是两个1，进位1，这里用与求进位，010&110=010，
 * 但是，进位是向前进1，所以这个进位的结果还需要向左移位1，得到100，
 * 于是100+100=1000.这就是最后的结果。但是题目的要求是不能使用+号，
 * 于是原来的问题又转换成了如何求另外两个数的加法（异或的结果，与的结果），
 * 如此递归下去，什么时候计算停止呢？就是两个数之间的进位是0的时候，就可以直接返回异或的结果了。
 */

class Solution {
public:
    int getSum(int a, int b) {
        int c,d;
		c = a&b;
		d = a^b;
		while (c != 0) {
			c = c << 1;
			int d_tmp = c^d;//这里需要有临时变量存储异或值，因为之后还要验证两个数的进位是否为0
			c = c&d;
			d = d_tmp;
		}
		return d;
    }
};

//递归方法
class solution {
public:
	int Sum(int a, int b) {
		if (a == 0) {
			return b;
		}
		int sum = a^b;
		int carry = (a&b)<<1;
		return Sum(carry, sum);
	}
};