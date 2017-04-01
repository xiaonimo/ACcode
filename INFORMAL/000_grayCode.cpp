#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GrayCode {
public:
    vector<string> getGray(int n) {
        vector<string> res;
        if (n<=0)
            return res;
        if (n == 1)
            return vector<string>{"0", "1"};
        vector<string> r = getGray(n-1);
        for (auto str:r)
            res.push_back("0" + str);
        reverse(begin(r), end(r));
        for (auto str:r)
            res.push_back("1" + str);
        return res;
    }
};

int main() {
    GrayCode a;
    for (auto s:a.getGray(4))
        cout << s <<endl;
}
