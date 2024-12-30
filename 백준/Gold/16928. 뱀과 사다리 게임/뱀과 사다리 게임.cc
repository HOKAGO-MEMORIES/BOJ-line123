#include <iostream>
#include <queue>
using namespace std;

int board[101];
int ans[101];

void solve() {
	int n, m, s, e;
	cin >> n >> m;

	queue<int> q;

	for (int i = 0; i < m + n; i++) {
		cin >> s >> e;
		board[s] = e;
	}

	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = now + i;

			if (next > 100)
				continue;

			if (board[next] != 0) {
				next = board[next];
			}
			
			if (!ans[next]) {
				ans[next] = ans[now] + 1;
				q.push(next);
			}
			
		}
	}

	cout << ans[100] << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}