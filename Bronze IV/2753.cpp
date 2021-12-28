#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    
    if (!(a % 4) && a % 100 || !(a % 4) && !(a % 400)) cout << 1 << endl;
    else cout << 0 << endl;
    
    return 0;
}