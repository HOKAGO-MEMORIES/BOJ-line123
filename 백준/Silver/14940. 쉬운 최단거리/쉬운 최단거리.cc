#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1001;
int map[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int n, m;

void bfs() {
	while(!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if(map[nx][ny] == 1 && dist[nx][ny] == -1) {
					q.push({nx, ny});
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
			
		}
	}
}

void solve() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				q.push({i, j});
				dist[i][j] = 0;
			}	
				
			if (map[i][j] == 0)
				dist[i][j] = 0;
		}
	}

	bfs();

	for (int i = 0; i < n; i++)  {
		for (int j = 0; j < m; j++) 
			cout << dist[i][j] << " ";
		cout << '\n';
	}
		
}

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}