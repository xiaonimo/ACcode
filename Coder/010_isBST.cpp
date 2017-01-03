/* Title:
 * 字符串翻转
 */

#include <iostream>
#include <string>
using namespace std;

class Checker {
public:
	//递归版本
	bool checkBST1(TreeNode* root) {
		// write code here
		int _last_val = INT_MIN;
		return _check(root, _last_val);
	}
	bool _check(TreeNode* root, int &_last_val) {
		if (!root)
			return true;
		if (!_check(root->left, _last_val))
			return false;
		if (root->val < _last_val)
			return false;
		_last_val = root->val;
		if (!_check(root->right, _last_val))
			return false;
		return true;
	}

	//according to definition
	bool checkBST(TreeNode* root) {
		// write code here
		return _check(root, INT_MIN, INT_MAX);
	}
	bool _check(TreeNode* root, int min_val, int max_val) {
		if (!root)
			return true;
		if (root->val < min_val || root->val > max_val)
			return false;
		return _check(root->left, min_val, root->val) &&
			_check(root->right, root->val, max_val);
	}
};
 int main(int argc, char *argv[]) {
    
}

