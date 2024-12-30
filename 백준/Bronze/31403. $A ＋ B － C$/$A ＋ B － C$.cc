#include <iostream>
#include <string>
using namespace std;

void solve() {
    string a, b, c = "";
    cin >> a >> b >> c;
    cout << stoi(a) + stoi(b) - stoi(c) << '\n' << stoi (a + b) - stoi(c) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}