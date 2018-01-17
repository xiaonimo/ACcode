//打印汉诺塔的移动步骤
#include <iostream>
#include <vector>

using namespace std;

//将x从A移动到B
void _move(int x, string A, string B) {
    cout << "move " <<x << " from " << A << " to " << B <<endl;
}

//将1-n从A移动到C
void hanoi(int n, string A, string B, string C) {
    if (n == 1) {
        _move(n, A, C);
        return;
    }
    hanoi(n-1, A, C, B);
    _move(n, A, C);
    hanoi(n-1, B, A, C);
}

int main() {
    hanoi(4, "A", "B", "C");
}
