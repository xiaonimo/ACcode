#include <iostream>

using namespace std;

void f1(int a, int& b) {
    a = b;
}
void f2(int* a, int& b) {
    a = &b;
}
void f3(int* a, int& b) {
    *a = b;
}

int main() {
    int b = 10;
    int *a = new int;
    *a = 1;
    f1(*a, b);
    cout << *a << endl;

    *a = 1;
    f2(a, b);
    cout << *a <<endl;

    *a = 1;
    f3(a, b);
    cout << *a <<endl;
    return 0;
    //1 1 10
}
