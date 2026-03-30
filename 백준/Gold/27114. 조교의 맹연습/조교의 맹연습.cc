#include <iostream>
#include <algorithm>

using namespace std;

int K, INF = 1000001;
int energy[4];
int dp[1000001][4];

void solve(int K) {
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j < 4; j++) {
			if (dp[i][j] == INF) continue;

			for (int k = 1; k <= 3; k++) {
				int nextDir = (j + k) % 4;
				int nextEnergy = i + energy[k];

				if (nextEnergy <= K) {
					dp[nextEnergy][nextDir] = min(dp[nextEnergy][nextDir], dp[i][j] + 1);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K = 0;
	// 우 -> 뒤 -> 좌
	cin >> energy[3] >> energy[1] >> energy[2] >> K;

	for (int i = 0; i <= K; i++) 
		for (int j = 0; j < 4; j++) dp[i][j] = INF;
		
	dp[0][0] = 0;
	solve(K);

	if (dp[K][0] == INF) cout << -1 << '\n';
	else cout << dp[K][0] << '\n';

	return 0;
}
