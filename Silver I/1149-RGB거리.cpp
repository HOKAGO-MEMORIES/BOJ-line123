#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int dp[MAX][3];

void solve() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) 
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
	
	for (int i = 2; i <= n; i++) {
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][1], dp[i - 1][0]);
	}

	int ans = min(min(dp[n][0], dp[n][1]), dp[n][2]);
	cout << ans << '\n';
	
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}