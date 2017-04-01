#include <iostream>
#include <string>
using namespace std;

//输入字符串，通过变换，使得小写字母在前，大写字母在后
void transfer(string &str) {
    for (int i = 0;i<(int)str.size();++i) {
        if ('A'<=str[i] && str[i] <= 'Z')
            continue;
        int j = i;
        char tmp = str[i];
        while (j>0) {
            if (str[j-1] >= 'a' && str[j-1] <= 'z')
                break;
            str[j] = str[j-1];
            --j;
        }
        str[j] = tmp;
    }
    for (auto ch:str)
        cout << ch;
}
int main() {
    string str;
    cin >> str;
    transfer(str);
    return 0;
}
