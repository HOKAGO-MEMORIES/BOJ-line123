#include <iostream>
#include <queue>
using namespace std;

int M, N;
int arr[1001][1001];
bool ripe[1001][1001];

bool check_ripe(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M) {
		if (arr[x][y] == 0 && !ripe[x][y])
			return true;
		else
			return false;
	}
	else
		return false;
}

void solve() {
	queue<pair<pair<int, int>, int>> q;
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	int answer, day = 0, unripe = 0, nx, ny;
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 0)
				unripe++;

			if (arr[i][j] == 1) {
				ripe[i][j] = true;
				q.push({ { i, j }, 0 });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		day = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (check_ripe(nx, ny)) {
				ripe[nx][ny] = true;
				unripe--;
				q.push({ {nx, ny}, day + 1 });
			}
		}
	}

	if (!unripe)
		answer = day;
	else
		answer = -1;

	cout << answer << '\n';

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}