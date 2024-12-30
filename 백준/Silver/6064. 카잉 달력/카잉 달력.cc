#include <iostream>
using namespace std;

int gcd(int m, int n) {
	int r = m % n;

	if (r == 0)
		return n;
	else
		return gcd(n, r);
}

int lcm(int m, int n) {
	return m * n / gcd(m, n);
}

void solve() {
	int t, m, n, x, y, i;
	cin >> t;

	while (t--) {
		cin >> m >> n >> x >> y;
		int limits = lcm(m, n);

		for (i = x; i <= limits; i += m) {
			int y_prime = (i % n == 0) ? n : i % n;

			if (y_prime == y) {
				cout << i << '\n';
				break;
			}

		}

		if (i > limits)
			cout << -1 << '\n';
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}