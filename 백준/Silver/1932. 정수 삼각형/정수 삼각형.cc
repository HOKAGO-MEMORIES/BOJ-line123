#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 501;
int dp[MAX][MAX];

int maxPathSum(int n) {

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	int maxNum = 0;
	for (int k = 1; k <= n; k++) {
		if (dp[n][k] > maxNum)
			maxNum = dp[n][k];
	}

	return maxNum;
}

void solve() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];
		}
	}

	int ans = maxPathSum(n);
	cout << ans << '\n';
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}