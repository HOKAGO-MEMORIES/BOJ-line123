#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int MAX_INT = 1e8;

int getMinTime(int N, vector<vector<int>>& map) {
	vector<vector<int>> dist(N, vector<int>(N, MAX_INT));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	dist[0][0] = map[0][0];
	pq.push({ dist[0][0], {0, 0} });
	
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (cost > dist[x][y])	continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				int newCost = cost + map[nx][ny];

				if (newCost < dist[nx][ny]) {
					dist[nx][ny] = newCost;
					pq.push({ newCost, {nx, ny} });
				}
			}
		}
	}

	return dist[N - 1][N - 1];
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		vector<vector<int>> map(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) {
			string row;
			cin >> row;

			for (int j = 0; j < N; j++) {
				map[i][j] = row[j] - '0';
			}
		}

		int ans = getMinTime(N, map);
		cout << "#" << test_case << " " << ans << '\n';
	}

	return 0;
}