#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//生成数组的子数组
vector<vector<int>> sub_arrays(vector<int> arr) {
    vector<vector<int>> res;
    if (arr.empty()) {
        res.push_back(vector<int>{});
        return res;
    }
    if (arr.size() <= 1) {
        res.push_back(vector<int>{});
        res.push_back(arr);
        return res;
    }
    res = sub_arrays(vector<int>(begin(arr)+1, end(arr)));
    int sz = (int)res.size();
    for (int i=0; i<sz; ++i) {
        vector<int> tmp = res[i];
        tmp.push_back(arr[0]);
        res.push_back(tmp);
    }
    return res;
}

//一个数组中子数组最大值-最小值<=num的数量

int qmax_qmin(vector<int> arr, int num) {
    int cnt = 0;
    deque<int> qmax, qmin;
    int sz = (int)arr.size();
    int i = 0, j= 0;
    while (i<sz) {
        while (j<sz) {
            while (!qmax.empty() && arr[qmax.back()] <= arr[j]) qmax.pop_back();
            qmax.push_back(j);
            while (!qmin.empty() && arr[qmin.back()] >= arr[j]) qmin.pop_back();
            qmin.push_back(j);
            if (arr[qmax.front()] - arr[qmin.front()] > num) break;
            j++;
        }
        cnt += j-i;
        if (qmax.front() == i) qmax.pop_front();
        if (qmin.front() == i) qmin.pop_front();
        i++;
    }
    return cnt;
}

int main() {
    cout << qmax_qmin(vector<int>{1,2}, 2);
}
