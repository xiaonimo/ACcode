/* Title:
 * 找出任意一个重复的数字
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length < 0)
            return false;
        unordered_map<int, int> hmap;
        try {
            for (int i = 0; i<length; ++i) {
                if (hmap[numbers[i]]) {
                    *duplication = numbers[i];
                    return true;
                }
                ++hmap[numbers[i]];
            }
        }
        catch(exception err) {
            return false;
        }
        return false;
    }

    //time O(n) space O(1)
    int find_dup( int numbers[], int length) {
    for ( int i= 0 ; i<length; i++) {
        int index = numbers[i];
        if (index >= length) {
            index -= length;
        }
        if (numbers[index] >= length) {
            return index;
        }
        numbers[index] = numbers[index] + length;
        for (int j = 0;j<length;++j) {
            cout << numbers[j];
        }
        cout << endl;
    }
    return - 1 ;
}
};

int main(int argc, char *argv[]) {
    Solution s;
    int numbers[5] = {4,4,4,4,4};
    cout << s.find_dup(numbers, 5);
    return 0;
}
