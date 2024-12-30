#include <iostream>
using namespace std;

const int MAX = 1025;
int dp[MAX][MAX];

void solve() {
	int n, m, x1, x2, y1, y2;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dp[i][j];
			dp[i][j] += dp[i][j - 1];
		}

		for (int j = 1; j <= n; j++) 
			dp[i][j] += dp[i - 1][j];
	}

	while (m--) {
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}