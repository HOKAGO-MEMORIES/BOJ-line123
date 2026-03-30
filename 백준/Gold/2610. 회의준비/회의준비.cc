#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 10e6;
vector<vector<int>> dist;
bool visited[101];

void solve(int N) {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (i == k) continue;
			for (int j = 1; j <= N; j++) {
				if (j == k || i == j) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}


	vector<int> representatives;

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			vector<int> group;

			for (int j = 1; j <= N; j++) {
				if (dist[i][j] != INF) {
					visited[j] = true;
					group.push_back(j);
				}
			}

			int representative = -1;
			int minValue = INF;

			for (int candidate : group) {
				int maxDist = 0;

				for (int person : group) 
					maxDist = max(maxDist, dist[candidate][person]);
				
				if (maxDist < minValue) {
					minValue = maxDist;
					representative = candidate;
				}
			}

			representatives.push_back(representative);
		}
	}

	sort(representatives.begin(), representatives.end());

	cout << representatives.size() << '\n';
	for (int n : representatives)
		cout << n << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, K = 0;
	cin >> N >> K;

	dist = vector<vector<int>>(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N; i++)
		dist[i][i] = 0;

	int u, v;
	while (K--) {
		cin >> u >> v;
		dist[u][v] = dist[v][u] = 1;
	}

	solve(N);
	return 0;
}
