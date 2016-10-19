/* Title:
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //调整数组顺序使得奇数在前半部分，偶数在后半部分
    void reOrderArray(vector<int> &array) {
        vector<int> tmp=array;
        int i = 0;
        for (auto o:array) {
            if ((o&1) == 1)
                array[i++] = o;
        }
        for (auto e:tmp) {
            if ((e&1) == 0)
                array[i++] = e;
        }
    }
    //利用插入排序的思想
    void reOrderArray1(vector<int> &array) {
        for (int i = 0;i<array.size();++i) {
            if ((array[i] & 1) == 0)
                continue;
            //这一步是过滤店偶数，偶数不参与排序
            int j = i;
            int tmp = array[i];
            while (j>0) {
                if ((array[j-1]&1) == 1) {
                    break;
                }
                array[j] = array[j-1];
                --j;
            }
            array[j] = tmp;
        }
    }
};
int main() {
    Solution s;
    vector<int> vec{1,2,3,4,5,6,7};
    s.reOrderArray1(vec);
    for (auto v:vec)
        cout << v;

}
