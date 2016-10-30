/* Given a non-negative integer num, 
 * repeatedly add all its digits until the result has only one digit.
 * For example:
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. 
 * Since 2 has only one digit, return it.

/*
recuision
*/

class Solution {
public:
    int addDigits(int a) {
        if (a / 10 == 0) {
			return a;
		}
		int num = 0;
		while (a / 10 != 0) {
			num += (a % 10);
			a /= 10;
		}
		num += a;
		return addDigits(num);  
    }
};