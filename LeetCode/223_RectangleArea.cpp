/* Find the total area covered by two rectilinear rectangles in a 2D plane.
 * Each rectangle is defined by its bottom left corner and 
 * top right corner as shown in the figure.
 * Assume that the total area is never beyond the maximum possible value of int.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

class Solution {
public:
	//two slow
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int x1 = min(A, E); 
		int y1 = min(F, F);
		int x2 = max(C, G);
		int y2 = max(D, H);
		int area = 0;
		for (int i = x1; i <= x2; ++i) {
			for (int j = y1; j <= y2; ++j) {
				if (i >= A && i < C && j >= B && j < D) {
					++area;
					continue;
				}
				if (i >= E && i < G && j >= F && j < H)
					++area;
			}
		}
		return area;
	}

	int computeArea1(int A, int B, int C, int D, int E, int F, int G, int H) {
		int res = (A-C)*(B-D)+(E-G)*(F-H);
		int x1 = max(A, E), y1 = max(B, F);
		int x2 = min(C, G), y2 = min(D, H);
		if (x1 >= x2 || y1 >= y2)
			return res;
		return res - (x1-x2)*(y1-y2);
	}
};

int main()
{
	Solution s = Solution();
	cout << s.computeArea(0, 0, 50000, 40000, 0, 0, 50000, 40000);
	system("pause");
	return 0;
}