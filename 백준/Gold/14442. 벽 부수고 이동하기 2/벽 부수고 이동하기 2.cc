#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m, k;
int graph[1001][1001];
int dist[1001][1001][11];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct Node {
	int x, y, cnt;
};

bool isIn(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}

int solve() {	
	queue<Node> q;
	q.push({1, 1, 0});
	dist[1][1][0] = 1;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.x == n && cur.y == m) 
			return dist[cur.x][cur.y][cur.cnt];

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (isIn(nx, ny)) {
				if (graph[nx][ny] == 0 && dist[nx][ny][cur.cnt] == -1) {
					dist[nx][ny][cur.cnt] = dist[cur.x][cur.y][cur.cnt] + 1;
					q.push({nx, ny, cur.cnt});
				}

				if (graph[nx][ny] == 1 && cur.cnt < k && dist[nx][ny][cur.cnt + 1] == -1) {
					dist[nx][ny][cur.cnt + 1] = dist[cur.x][cur.y][cur.cnt] + 1;
					q.push({nx, ny, cur.cnt + 1});
				}
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= m; j++) {
			graph[i][j] = input[j - 1] - '0';
			for (int k = 0; k <= 10; k++) {
				dist[i][j][k] = -1;
			}
		}
	}

	cout << solve() << '\n';
}