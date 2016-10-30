/* Title:
 * You are playing the following Nim Game with your friend: 
 * There is a heap of stones on the table, each time one of you take turns 
 * to remove 1 to 3 stones. The one who removes the last stone will be the winner. 
 * You will take the first turn to remove the stones.
 * Both of you are very clever and have optimal strategies for the game. 
 
 * Write a function to determine whether you can win the game given the number 
 * of stones in the heap.

 * For example, if there are 4 stones in the heap, 
 * then you will never win the game: no matter 1, 2, or 3 stones you remove, 
 * the last stone will always be removed by your friend.
 */

/*Solutions
注意到一点（先手为甲，后手为乙），如果最后剩4个石子，且还是甲先手，那么甲必输。如果还是甲先手，那么意味着前n-4个石子拿取过程中，乙始终能拿到最后一个石子，也就是题目中规定的赢。所以，类推下去，甲必输的条件是，甲乙任何一组（甲乙先后的各拿一次），甲必输，乙必能拿到最后一个石子。所以如果石子数量是4的整数倍，那么甲必输。
*/

//该方法简洁效率高
class Solution {
public:
    bool canWinNim(int n) {
        return n%4!=0;
    }
};

class Solution {
public:
    bool canWinNim(int n) {
        if (n%4 == 0) {
			return false;
		}
		return true;
    }
};