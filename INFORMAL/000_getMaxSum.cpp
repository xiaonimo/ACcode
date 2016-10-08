/* 题目：
 * 一个只含有数字的字符串 如“123123343”，在该字符串中添加n个加号，
 * 使得表达式的和最小，求出加号的位置
 * 如“123”，n=1,那么和最小的添加方式是“12+3”。输出加号位置是2.
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//把字符串转化成对应的整数
//例如,"123"的str2int值就是123
int str2int(string str) {
	if (str.size() <= 0) return 0;
	int sum = 0;
	for (int i = 0; i < (int)str.size(); ++i) {
		sum = 10 * sum + (str[i] - '0');
	}
	return sum;
}
//把字符串中每个数字分别相加
//例如,"123"的strSum就是6
int strSum(string str) {
	int sum = 0;
	for (int i = 0; i < (int)str.size(); ++i) {
		sum = sum + (str[i] - '0');
	}
	return sum;
}

class Solution {
public:
	vector<int> getMinSum(string str, int n) {
		vector<int> recordpos;
		if (str.empty()) return recordpos;

		int sz = str.size();
		n = sz <= n ? sz - 1 : n;
		//pair.first表示当前sum值，second存储加号位置
		vector<vector<pair<int, int>>> dp(sz + 1, vector<pair<int, int>>(n + 1, {INT_MAX, 0}));

		for (int i = 0; i <= sz; ++i) {
			dp[i][0].first = str2int(str.substr(0, i));
		}
		for (int j = 0; j <= n; ++j) {
			dp[0][j].first = 0;
		}
		for (int i = 1; i < sz + 1; ++i) {
			for (int j = 1; j < n + 1; ++j) {
				if (j >= i)
					dp[i][j].first = strSum(str.substr(0, i));
				else {
					for (int k = 1; k <= i; ++k) {
						if (dp[i][j].first > dp[k][j - 1].first + str2int(str.substr(k, i - k))) {
							dp[i][j].first = dp[k][j - 1].first + str2int(str.substr(k, i - k));
							dp[i][j].second = k;
						}
					}
				}
			}
		}
		/*for (int i = 1; i <= sz; ++i) {
			for (int j = 1; j <= n; ++j) {
				cout << "(" << dp[i][j].first<<"," << dp[i][j].second <<")" << "\t";
			}
			cout << endl;
		}
		cout << endl;*/
		int pos = dp[sz][n].second;
		while (pos > 0 && n > 0) {
			recordpos.push_back(pos);
			pos = dp[pos][--n].second;
		}
		return recordpos;
	}
};
int main(){
	Solution s = Solution();
	vector<int> rec;

	rec = s.getMinSum("46546484", 3);
	for (int i = 0; i < rec.size(); i++){
		cout << rec[i] << " ";
	}

	system("pause");
	return 0;
}
