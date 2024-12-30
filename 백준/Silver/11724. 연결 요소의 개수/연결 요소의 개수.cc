#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[1001];
bool check[1001];
int M;

void graph_check(int n) {
	check[n] = true;

	while (!vec[n].empty()) {
		int next = vec[n].back();
		vec[n].pop_back();

		if (!check[next])
			graph_check(next);
	}
}

void solve() {
	int N, u, v;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			graph_check(i);
			answer++;
		}
	}

	cout << answer << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}