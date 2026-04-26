#include <iostream>
using namespace std;

int a, b, n, k;

void solve() {
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (k <= n) {
				cout << i << " " << j << '\n';
				return;
			} else {
				k -= n;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b >> n >> k;

	solve();
	return 0;
}
