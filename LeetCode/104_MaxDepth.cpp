/* title
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path 
 * from the root node down to the farthest leaf node.

  分为两个办法，一种是广度优先，采用循环，一层一层的向下遍历，直到没有页节点，记录层数，就是树的最大深度
  深度优先，就是纵向的遍历，把每一条路径都走一遍，找出最大深度。
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//树节点的结构体
struct treeNode{
	int val;
	treeNode *left;
	treeNode *right;
	//构造函数
	treeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

//嵌套的形式对树进行遍历
void scanTree(treeNode *root) {
	if (!root) {
		return;
	}
	else {
		cout << root->val << endl;
	}
	if (root->left) {
		scanTree(root->left);
	}
	if (root->right) {
		scanTree(root->right);
	}
}

class solution {
public:
	int maxDepth(treeNode *root){
		//深度优先，通过嵌套的形式实现
		return !root ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
	//广度优先，查看树分多少层。就是深度
	int maxDepth1(treeNode *root) {
		if (!root) {
			return 0;
		}
		queue<treeNode*> s;//用来存储每一层的节点
		int res = 0;//保存树的深度
		s.push(root);
		while (!s.empty()) {
			res++;
			for (int i = 0, n = s.size(); i < n; ++i) {
				treeNode *p = s.front();
				if (p->left) {
					s.push(p->left);
				}
				if (p->right) {
					s.push(p->right);
				}
				s.pop();
			}
		}
		return res;
	}
};
int main()
{
	//构造一棵树
	struct treeNode *root = new treeNode(0);
	struct treeNode *p1 = new treeNode(1);
	struct treeNode *p2 = new treeNode(2);
	struct treeNode *p3 = new treeNode(3);
	struct treeNode *p4 = new treeNode(4);
	struct treeNode *p5 = new treeNode(5);
	struct treeNode *p6 = new treeNode(6);
	
	root->left = p1;
	root->right = p2;
	p1->left = p3;
	p2->left = p4;
	p2->right = p5;
	p4->right = p6;

	scanTree(root);
	solution s = solution();
	cout << "depth=" <<s.maxDepth1(root) << endl;
	system("pause");
	return 0;
}