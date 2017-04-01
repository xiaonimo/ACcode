#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

//求最少删除多少字母，字符串可以变为回文串
int LCS(string str) {
    string str1 = str;
    reverse(begin(str), end(str));
    string str2 = str;
    int sz1 = str1.size();
    int sz2 = str2.size();
    int arr[sz1+1][sz2+1];
    memset(arr, 0, sizeof(arr));
    for (int i = 1;i<=sz1;++i) {
        for (int j = 1;j<=sz2;++j) {
            if (str1[i] == str2[j])
                arr[i][j] = arr[i-1][j-1]+1;
            else {
                cout << arr[i-1][j] << " " << arr[i][j-1] <<endl;
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    return arr[sz1][sz2];
}
int main() {
    string str;
    cin >> str;
    cout << (int)str.size() - LCS(str);
    return 0;
}
