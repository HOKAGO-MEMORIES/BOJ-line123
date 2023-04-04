#include <iostream>
using namespace std;

void solve() {

	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	if (a1 <= c && (a1 * n0 + a0) <= (c * n0))
		cout << 1 << '\n';
	else	
		cout << 0 << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}