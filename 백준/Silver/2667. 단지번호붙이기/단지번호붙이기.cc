#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int n, c;
int arr[25][25];
int visit[25][25];
vector<int> complex;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void bfs(int x, int y) {
	int count = 1;
	visit[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n) {
				if (arr[next_x][next_y] == 1 && !visit[next_x][next_y]) {
					visit[next_x][next_y] = true;
					count++;
					q.push({ next_x, next_y });
				}
			}
		}

	}
	complex.push_back(count);
}

void solve() {

	cin >> n;

	string num = "";

	for (int i = 0; i < n; i++) {
		cin >> num;
		for (int j = 0; j < n; j++) {
			arr[i][j] = (num[j] - '0');
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !visit[i][j]) {
				bfs(i, j);
				c++;
			}
		}
	}

	sort(complex.begin(), complex.end());
	cout << c << '\n';
	int size = complex.size();
	for (int i = 0; i < size; i++)
		cout << complex[i] << '\n';

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();


	return 0;
}