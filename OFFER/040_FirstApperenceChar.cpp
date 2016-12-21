/* Title:
 * 找到字符流中第一个只出现一次的字符
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
private:
    queue<char> que;
    unordered_map<char, int> hmap;
public:
    //Insert one char from stringstream
    void Insert(char ch) {
        if (!hmap[ch])
            que.push(ch);
        ++hmap[ch];
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while (!que.empty() && hmap[que.front()] >= 2)
            que.pop();
        return que.empty()?'#':que.front();
    }

};
 int main(int argc, char *argv[]) {
    Solution s;
    string str("google");
    for (auto c:str) {
        s.Insert(c);
        cout << s.FirstAppearingOnce() <<endl;
    }


}

