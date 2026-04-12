#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
pair<int, int> start;
char graph[50][50];
int dist[50][50][1 << 6];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct Node {
	int x, y, bit;
};

bool isIn(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && graph[x][y] != '#';
}

int solve() {	
	queue<Node> q;
	q.push({start.first, start.second, 0});
	dist[start.first][start.second][0] = 0;

	while(!q.empty()) {
		Node cur = q.front();
		q.pop();
		
		int x = cur.x;
		int y = cur.y;
		int bit = cur.bit;

		if (graph[x][y] == '1')
			return dist[x][y][bit];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nBit = bit;

			if (!isIn(nx, ny)) continue;

			if (graph[nx][ny] >= 'a' && graph[nx][ny] <= 'f') {
				nBit = bit | (1 << (graph[nx][ny] - 'a'));
			}
			else if (graph[nx][ny] >= 'A' && graph[nx][ny] <= 'F') {
				if (!(bit & (1 << (graph[nx][ny] - 'A')))) continue;
			}
			
			if (dist[nx][ny][nBit] == -1) {
				dist[nx][ny][nBit] = dist[x][y][bit] + 1;
				q.push({nx, ny, nBit});
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			graph[i][j] = input[j];
			if (graph[i][j] == '0') start = make_pair(i, j);
		}
	}

	cout << solve() << '\n';
	return 0;
}