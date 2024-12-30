#include <iostream>
#include <queue>
using namespace std;

int N, K, answer;
bool visit[100001];
queue<pair<int, int>> q;

void solve() {

	while (!q.empty()) {

		int data = q.front().first;
		int count = q.front().second;
		q.pop();

		if (data == K) {
			answer = count;
			break;
		}

		if (data + 1 >= 0 && data + 1 < 100001 && !visit[data + 1] ) {
			visit[data + 1] = true;
			q.push({ data + 1, count + 1 });
		}

		if (data - 1 >= 0 && data - 1 < 100001 && !visit[data - 1]) {
			visit[data - 1] = true;
			q.push({ data - 1, count + 1 });
		}

		if (data * 2 >= 0 && data * 2 < 100001 && !visit[data * 2]) {
			visit[data * 2] = true;
			q.push({ data * 2, count + 1 });
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	q.push({ N , 0 });
	solve();

	cout << answer << '\n';

	return 0;
}