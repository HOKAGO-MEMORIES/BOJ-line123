#include <iostream>
using namespace std;

void solve() {

	long long n;
	cin >> n;

	cout << (n * (n - 1) * (n - 2)) / 6 << '\n' << 3 << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}