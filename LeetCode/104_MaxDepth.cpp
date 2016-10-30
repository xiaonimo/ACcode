/* title
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path 
 * from the root node down to the farthest leaf node.

  ��Ϊ�����취��һ���ǹ�����ȣ�����ѭ����һ��һ������±�����ֱ��û��ҳ�ڵ㣬��¼��������������������
  ������ȣ���������ı�������ÿһ��·������һ�飬�ҳ������ȡ�
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//���ڵ�Ľṹ��
struct treeNode{
	int val;
	treeNode *left;
	treeNode *right;
	//���캯��
	treeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

//Ƕ�׵���ʽ�������б���
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
		//������ȣ�ͨ��Ƕ�׵���ʽʵ��
		return !root ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
	//������ȣ��鿴���ֶ��ٲ㡣�������
	int maxDepth1(treeNode *root) {
		if (!root) {
			return 0;
		}
		queue<treeNode*> s;//�����洢ÿһ��Ľڵ�
		int res = 0;//�����������
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
	//����һ����
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