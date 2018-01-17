#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int hist_max_area(vector<int> hist) {
    if (hist.empty()) return 0;
    int max_area = 0;
    stack<int> sta;
    for (int i=0; i<(int)hist.size(); ++i) {
        while (!sta.empty() && hist[sta.top()] >= hist[i]) {
            int _top = sta.top();
            sta.pop();
            int k = sta.empty()?-1:sta.top();
            max_area = max(max_area, (i-k-1)*hist[_top]);
        }
        sta.push(i);
    }
    while (!sta.empty()) {
        int _top = sta.top();
        sta.pop();
        int k = sta.empty()?-1:sta.top();
        max_area = max(max_area, ((int)hist.size()-k-1)*hist[_top]);
    }
    return max_area;
}

//这里非常精髓
//j能向左最大扩展到K+1， 向右最大能扩展到i-1
//所以面积是[(i-1)-(k+1)+1]*hist[j];
int rectangle_max_area(const vector<vector<int>> rect) {
    if (rect.empty()) return 0;
    int row = rect.size();
    int col = rect[0].size();
    int max_area = 0;
    vector<int> hist(col, 0);
    for (int i=0;i<row;++i) {
        for (int j=0;j<col;++j) {
            hist[j] = rect[i][j]==0?0:hist[j]+1;
        }
        max_area = max(max_area, hist_max_area(hist));
    }
    return max_area;
}


int main() {
    cout << hist_max_area(vector<int>{3,4,5,4,3,6});
}
