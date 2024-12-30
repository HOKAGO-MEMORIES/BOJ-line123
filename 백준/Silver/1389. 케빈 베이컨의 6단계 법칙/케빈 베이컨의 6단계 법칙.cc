#include <iostream>
#define INF 2147483647
using namespace std;

int friends[101][101];

void solve() {
	int n, m, x, y;
	cin >> n >> m;

	while (m--) {
		cin >> x >> y;
		friends[x][y] = 1;
		friends[y][x] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) 
					continue;
				else if (friends[i][k] && friends[k][j]) {
					if (friends[i][j] != 0) {
						friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);
					}
					else {
						friends[i][j] = friends[i][k] + friends[k][j];
					}
				}
			}
		}
	}

	int min_sum = INF;
	int answer = 0;
	for (int a = 1; a <= n; a++) {
		int sum = 0;
		for (int b = 1; b <= n; b++) {
			sum += friends[a][b];
		}

		if (sum < min_sum) {
			min_sum = sum;
			answer = a;
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