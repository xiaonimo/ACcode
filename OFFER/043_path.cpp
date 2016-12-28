/* Title:
 * 找到字符流中第一个只出现一次的字符
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
    vector<vector<char>> _matrix;
    vector<vector<bool>> _pass;
    vector<vector<int>> pos{{0,-1},{-1,0},{0,1},{1,0}};
    int r;
    int c;
public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        _init(matrix, rows,cols);
        for (int i = 0;i<rows;++i) {
            for (int j = 0;j<cols;++j) {
                if (_hasPath(_pass, i, j, str))
                    return true;
            }
        }
        return false;
    }
    void _init(char* matrix, int rows, int cols) {
        _matrix = vector<vector<char>>(rows, vector<char>(cols));
        _pass   = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for (int i = 0;i<rows;++i) {
            for (int j = 0;j<cols;++j)
                _matrix[i][j] = *(matrix+i*cols+j);
        }
        r = rows;
        c = cols;
    }
    bool _hasPath(vector<vector<bool>> pass, int x, int y, char* str) {
        if (*str == '\0')
            return true;
        if (x <0 || x >= r || y<0 || y>=c )
            return false;
        if (!pass[x][y] && _matrix[x][y] == *str) {
            pass[x][y] = true;
            for (auto p:pos) {
                if (_hasPath(pass, x+p[0], y+p[1], str+1)) {
                    cout << x+p[0] <<y+p[1] <<endl;
                    return true;
                }
            }
        }
        return false;
    }
};
 int main(int argc, char *argv[]) {
    Solution s;
    cout << s.hasPath("A",1,1,"A");

    return 0;
}

