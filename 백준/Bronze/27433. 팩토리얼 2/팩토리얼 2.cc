#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }

    cout << ans;
}