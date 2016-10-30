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
ע�⵽һ�㣨����Ϊ�ף�����Ϊ�ң���������ʣ4��ʯ�ӣ��һ��Ǽ����֣���ô�ױ��䡣������Ǽ����֣���ô��ζ��ǰn-4��ʯ����ȡ�����У���ʼ�����õ����һ��ʯ�ӣ�Ҳ������Ŀ�й涨��Ӯ�����ԣ�������ȥ���ױ���������ǣ������κ�һ�飨�����Ⱥ�ĸ���һ�Σ����ױ��䣬�ұ����õ����һ��ʯ�ӡ��������ʯ��������4������������ô�ױ��䡣
*/

//�÷������Ч�ʸ�
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