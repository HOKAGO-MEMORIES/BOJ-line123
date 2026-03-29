#include <iostream>
using namespace std;

void solve() {
    int m, f;

    while(true) {
        cin >> m >> f;
        if (m == 0 && f == 0)    
            break;
        cout << m + f << '\n';
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
