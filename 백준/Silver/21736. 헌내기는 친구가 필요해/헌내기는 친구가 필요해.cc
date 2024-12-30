#include <iostream>
using namespace std;

const int MAXN = 601;
char campus[MAXN][MAXN];
bool visit[MAXN][MAXN];

int n, m, x, y, cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
	visit[x][y] = true;
		
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
			
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (campus[nx][ny] != 'X' && !visit[nx][ny]) {
				
				if (campus[nx][ny] == 'P')
					cnt++;

				dfs(nx, ny);
			}
		}			
	}

	return;
}

void solve() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> campus[i][j];

			if (campus[i][j] == 'I') {
				x = i;
				y = j;
			}
		}
	}

	dfs(x, y);
	
	if (cnt == 0)
		cout << "TT" << '\n';
	else
		cout << cnt << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}