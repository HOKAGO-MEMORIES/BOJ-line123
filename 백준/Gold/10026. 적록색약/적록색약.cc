#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int n, int x, int y, vector<vector<int>> &v, vector<vector<bool>> &visit) {

	visit[x][y] = true;
	int num = v[x][y];

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && v[nx][ny] == num) 
			dfs(n, nx, ny, v, visit);
	}


}

void solve() {
	int n;
	cin >> n;

	// R: 0, G: 1: B: 2
	vector<vector<int>> v1(n, vector<int>(n, 0));
	vector<vector<bool>> v1_visit(n, vector<bool>(n, false));
	vector<vector<int>> v2(n, vector<int>(n, 0));
	vector<vector<bool>> v2_visit(n, vector<bool>(n, false));

	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;

			switch (c) {
			case 'R':
				v1[i][j] = 0;
				v2[i][j] = 0;
				break;
			case 'G':
				v1[i][j] = 1;
				v2[i][j] = 0;
				break;
			case 'B':
				v1[i][j] = 2;
				v2[i][j] = 2;
				break;
			}
		}
	}

	int a1 = 0, a2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!v1_visit[i][j]) {
				dfs(n, i, j, v1, v1_visit);
				a1++;
			}

			if (!v2_visit[i][j]) {
				dfs(n, i, j, v2, v2_visit);
				a2++;
			}
		}
	}

	cout << a1 << " " << a2 << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}