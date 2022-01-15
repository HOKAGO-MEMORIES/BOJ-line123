#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> dfs_tree[1001];
priority_queue<int, vector<int>, greater<int>> bfs_tree[1001];
queue<int> bfs_queue;
int dfs_check[1001];
int bfs_check[1001];
queue<int> result;

void dfs(int v) {
	dfs_check[v] = true;
	result.push(v);

	while (!dfs_tree[v].empty()) {
		int next = dfs_tree[v].top();
		dfs_tree[v].pop();

		if (!dfs_check[next])
			dfs(next);
	}
}

void bfs(int v) {
	bfs_queue.push(v);

	while (!bfs_queue.empty()) {
		int next = bfs_queue.front();
		bfs_queue.pop();

		if (!bfs_check[next]) {
			bfs_check[next] = true;
			result.push(next);

			while (!bfs_tree[next].empty()) {
				bfs_queue.push(bfs_tree[next].top());
				bfs_tree[next].pop();
			}
		}
	}
}

void print_result() {
	int size = result.size();
	while (size--) {
		cout << result.front() << " ";
		result.pop();
	}
	cout << '\n';
}

void solve() {
	int n, m, v, s, e;
	cin >> n >> m >> v;

	while (m--) {
		cin >> s >> e;
		dfs_tree[s].push(e);
		dfs_tree[e].push(s);
		bfs_tree[s].push(e);
		bfs_tree[e].push(s);
	}

	dfs(v);
	print_result();

	bfs(v);
	print_result();
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}