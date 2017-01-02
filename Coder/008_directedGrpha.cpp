/* Title:
* cat and dog
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<struct UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) : label(x) {}
};

class Path {
	map<UndirectedGraphNode*, int> hmap;
public:
	bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
		// write code here
		return _checkPath(a, b) || _checkPath(b, a);
	}

	bool _checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
		// write code here
		if (a == nullptr || b == nullptr)
			return false;
		if (a == b)
			return true;
		for (auto n : a->neighbors) {
			if (hmap[n])
				continue;
			hmap[n]++;
			if (_checkPath(n, b))
				return true;
		}
		return false;
	}
};
int main(int argc, char *argv[]) {


	system("pause");
	return 0;
}

