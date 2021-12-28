#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e;
    cin >> a >> b;

    d = b % 100;
    c = d % 10;
    e = b / 100;
    d = d / 10;

    cout << a * c << endl;
    cout << a * d << endl;
    cout << a * e << endl;
    cout << a * b << endl;

    return 0;
}