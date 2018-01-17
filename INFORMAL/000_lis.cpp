#include <iostream>
#include <vector>

using namespace std;

int getHeight(vector<int> men, int n) {
	// write code here
	vector<int> dp(n);
	int res = 0;
	for (int i = 0; i<n; ++i) {
		dp[i] = 1;
		for (int j = 0; j<i; ++j) {
			if (men[i] < men[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		if (res < dp[i])
			res = dp[i];
	}
	return res;
}

int getHeight1(vector<int> men, int n) {
	// write code here
	vector<int> dp(n);
	int len = 0;
	dp[0] = men[0];
	for (int i = 1; i<n; ++i) {
		if (dp[len] <= men[i]) {
			dp[len + 1] = men[i];
			len++;
		}
		else {
			int beg = 0, lat = len, mid;
			while (beg < lat) {
				mid = beg + (lat - beg) / 2;
				if (men[i] < dp[mid])
					lat = mid;
				else if (men[i] > dp[mid])
					beg = mid + 1;
				else {
					beg = mid;
					break;
				}
			}
			dp[beg] = men[i];
		}
	}
	return len + 1;
}
int main() {
	cout << getHeight1(vector<int>{1, 6, 2, 5, 3, 4, 4}, 7);
	system("pause");
	return 0;
}