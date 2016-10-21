/* Title:
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};
class Solution {
public:
    //Mirror tree
    void Mirror(TreeNode *pRoot) {
        if (pRoot == nullptr) return;
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }

    //分层打印树
    vector<int> PrintFromTopToBottom(TreeNode *root) {
		vector<int> res;
		if (root == nullptr) return res;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
            int sz = que.size();
            for (int i = 0;i<sz;++i) {
                TreeNode* tmp = que.front();
                que.pop();
                if (tmp->left)
                    que.push(tmp->left);
                if (tmp->right)
                    que.push(tmp->right);
                res.push_back(tmp->val);
            }
		}
		return res;
    }

    /* 输入一个矩阵，按照从外向里以顺时针的顺序依次打印
     * 出每一个数字，例如，如果输入如下矩阵：
     * [1 2 3 4; 5 6 7 8; 9 10 11 12; 13 14 15 16]
     * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
     */
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.empty()) return vector<int>();
        int row = matrix.size(), col = matrix[0].size();
        vector<int> res;
        int i = 0, j = 0;
        while (i<(row+1)/2 && j<(col+1)/2) {
            printEdge(matrix, i, j, row-2*i, col-2*i, res);
            ++i;
            ++j;
        }
        return res;
    }
    void printEdge(vector<vector<int> > m, int i, int j, int row, int col, vector<int> &res) {
        int it = i, jt = j;
        for (;jt-j<col;++jt)
            res.push_back(m[it][jt]);
        --jt;
        ++it;
        if (row == 1) return;
        for (;it-i<row-1;++it)
            res.push_back(m[it][jt]);

        for (;jt-j>=0;--jt)
            res.push_back(m[it][jt]);
        ++jt;
        --it;
        if (col == 1) return;
        for (;it-i>0;--it)
            res.push_back(m[it][jt]);
    }

    //定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
    vector<int> data;
    vector<int> min_data;
    void push(int value) {
        data.push_back(value);
        if (min_data.empty() || value < min_data.back())
            min_data.push_back(value);
    }
    void pop() {
        if (data.back() == min_data.back())
            min_data.pop_back();
        data.pop_back();
    }
    int top() {
        return data.back();
    }
    int min() {
        return min_data.back();
    }
};
int main() {
    Solution s;
    char str[10];
    cin >> str;
    cout << str;
}
