/* Given two arrays, write a function to compute their intersection.
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> s1;
		vector<int> v;
		s1.insert(nums1.begin(), nums1.end());
		for (auto i : nums2) {
			if (s1.find(i) != s1.end()) {
				v.push_back(i);
				s1.erase(i);
			}
		}
		return v;
	}
	vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_map<int, int> hashmap1;
		//store the elements of nums1 in hashmap1
		for (int k : nums1){
			if (hashmap1.find(k) == hashmap1.end()){
				hashmap1[k] = 1;
			}
		}
		//find the common values and avoid duplicates
		for (int k : nums2){
			if ((hashmap1.find(k) != hashmap1.end()) && (hashmap1[k] == 1)){
				result.push_back(k);
				hashmap1[k] = 0;
			}
		}
		return result;
	}
	vector<int> intersection3(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> s1(nums1.begin(), nums1.end());//it's not important how to declare the set.
		vector<int> v;
		for (auto i : nums2) {
			if (s1.count(i)) {//count()do not need to compare,so it cost less
				v.push_back(i);
				s1.erase(i);
			}
		}
		return v;
	}
};
int main()
{
	int a[7] = { 1, 0, 3, 0, 0, 4, 0 };
	int b[3] = { 5, 1, 3 };
	vector<int> nums3;
	vector<int> nums1(begin(a), end(a));
	vector<int> nums2(begin(b), end(b));
	Solution s = Solution();

	nums3 = s.intersection3(nums1, nums2);
	for (auto i : nums3)
		cout << i;
	
	system("pause");
	return 0;
}