/* Title:
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //��������˳��ʹ��������ǰ�벿�֣�ż���ں�벿��
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
    //���ò��������˼��
    void reOrderArray1(vector<int> &array) {
        for (int i = 0;i<array.size();++i) {
            if ((array[i] & 1) == 0)
                continue;
            //��һ���ǹ��˵�ż����ż������������
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
