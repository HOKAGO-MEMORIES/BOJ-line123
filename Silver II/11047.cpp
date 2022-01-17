#include <iostream>
using namespace std;

void solve() {
	int n, k, answer = 0;
	cin >> n >> k;
	
	int money[11] = {};
	for (int i = 0; i < n; i++)
		cin >> money[i];

	for (int j = n - 1; j >= 0; j--) {
		if (k == 0)
			break;

		while (money[j] <= k) {
			k -= money[j];
			answer++;
		}
	}

	cout << answer << '\n';
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}