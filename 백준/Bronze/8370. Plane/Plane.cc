#include <iostream>
using namespace std;

void solve() {
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	cout << n1 * n2 + k1 * k2 << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}