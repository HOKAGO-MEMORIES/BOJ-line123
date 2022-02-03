#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool visit[10000];
char dslr[4] = { 'D', 'S', 'L', 'R' };

int D(int n) {
	return (n * 2) % 10000;
}

int S(int n) {
	return (n + 9999) % 10000;
}

int L(int n) {
	return (n % 1000 * 10) + (n / 1000);
}

int R(int n) {
	return (n / 10) + (n % 10 * 1000);
}

string bfs(int s, int e) {
	queue<pair<int, string>> q;
	visit[s] = true;
	q.push({ s, "" });

	while (!q.empty()) {
		int n = q.front().first;
		string st = q.front().second;
		q.pop();

		if (n == e) 
			return st;

		int get_ans[4] = { D(n), S(n), L(n), R(n) };

		for (int i = 0; i < 4; i++) {
			if (!visit[get_ans[i]]) {
				q.push({ get_ans[i], st + dslr[i] });
				visit[get_ans[i]] = true;
			}
		}
	}
}

void solve() {
	int t, s, e;
	cin >> t;

	while (t--) {
		memset(visit, false, sizeof(visit));
		cin >> s >> e;

		cout << bfs(s, e) << '\n';
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}