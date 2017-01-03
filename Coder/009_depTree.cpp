/* Title:
 * 打印二叉树的某一层
 */

#include <iostream>
#include <string>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class TreeLevel {
public:
	//非递归版本
	ListNode* getTreeLevel(TreeNode* root, int dep) {
		// write code here
		if (root == nullptr || dep < 0)
			return nullptr;
		queue<TreeNode*> que;
		que.push(root);
		ListNode* res = nullptr;
		int _dep = 1;
		while (!que.empty()) {
			if (dep == _dep) {
				res = new ListNode((que.front())->val);
				ListNode* cur = res;
				que.pop();
				while (!que.empty()) {
					cur->next = new ListNode((que.front())->val);
					que.pop();
					cur = cur->next;
				}
				break;
			}
			auto sz = que.size();
			for (unsigned i = 0; i < sz; ++i) {
				TreeNode* f = que.front();
				if (f->left) que.push(f->left);
				if (f->right) que.push(f->right);
				que.pop();
			}
			++_dep;
		}
		return res;
	}
	//递归版本
	ListNode* getTreeLevel1(TreeNode* root, int dep) {
		// write code here
		if (root == nullptr || dep < 0)
			return nullptr;
		return _getTreeLevel(root, dep, 1);
	}
	ListNode* _getTreeLevel(TreeNode* root, int dep, int _dep) {
		if (!root)
			return nullptr;
		if (_dep == dep) {
			ListNode* res = new ListNode(root->val);
			return res;
		}
		ListNode* left = _getTreeLevel(root->left, dep, _dep + 1);
		ListNode* right = _getTreeLevel(root->right, dep, _dep + 1);
		if (left == nullptr && right == nullptr)
			return nullptr;
		else if (left == nullptr)
			return right;
		else if (right == nullptr)
			return left;
		else {
			ListNode* res = left;
			while (left->next) left = left->next;
			left->next = right;
			return res;
		}
		return nullptr;
	}
};
int main(int argc, char *argv[]) {

}

