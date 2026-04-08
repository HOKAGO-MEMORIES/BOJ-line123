#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int W, H;
char graph[100][100];
int dist[100][100][4];
pair<int, int> s, e;

const int INF = 1e9;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct Node {
	int x, y, d, c;

	bool operator<(const Node n) const {
		return c > n.c;
	}
};

int solve() {
	priority_queue<Node> q;
	for (int i = 0; i < 4; i++) {
		q.push({ s.first, s.second, i, 0 });
		dist[s.first][s.second][i] = 0;
	}

	int ans = INF;
	while (!q.empty()) {
		Node cur = q.top();
		q.pop();

		if (cur.x == e.first && cur.y == e.second) {
			ans = min(ans, cur.c);
			continue;
		}

		if (dist[cur.x][cur.y][cur.d] < cur.c) continue;

		int nx = cur.x + dx[cur.d];
		int ny = cur.y + dy[cur.d];

		if (nx >= 0 && ny >= 0 && nx < H && ny < W && graph[nx][ny] != '*') {
			if (dist[nx][ny][cur.d] > cur.c) {
				dist[nx][ny][cur.d] = cur.c;
				q.push({ nx, ny, cur.d, cur.c });
			}

			int nd1 = (cur.d + 1) % 4;
			int nd2 = (cur.d + 3) % 4;
			int nc = cur.c + 1;

			if (dist[nx][ny][nd1] > nc) {
				dist[nx][ny][nd1] = nc;
				q.push({ nx, ny, nd1, nc });
			}

			if (dist[nx][ny][nd2] > nc) {
				dist[nx][ny][nd2] = nc;
				q.push({ nx, ny, nd2, nc });
			}
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> W >> H;

	bool flag = false;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'C') {
				if (!flag) {
					s = make_pair(i, j);
					flag = true;
				}
				else {
					e = make_pair(i, j);
				}
			}

			for (int d = 0; d < 4; d++) {
				dist[i][j][d] = INF;
			}
		}
	}

	cout << solve() << '\n';
	
	return 0;
}
