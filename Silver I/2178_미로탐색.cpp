#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
int arr[101][101];
int dist[101][101];
bool visit[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve(int x, int y) {

	visit[x][y] = true;
	dist[x][y] = 1;
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m) {
				if (arr[next_x][next_y] == 1 && !visit[next_x][next_y]) {
					visit[next_x][next_y] = true;
					dist[next_x][next_y] = dist[x][y] + 1;
					q.push({ next_x, next_y });
				}
			}
		}

	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	string num = "";
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		for (int j = 0; j < m; j++) {
			arr[i][j] = (num[j] - '0');
		}
	}

	solve(0, 0);

	cout << dist[n - 1][m - 1] << '\n';

	return 0;
}