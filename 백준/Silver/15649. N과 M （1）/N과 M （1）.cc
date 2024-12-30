#include <iostream>
using namespace std;

int arr[10];
bool visit[10];

void dfs(int n, int m, int depth) {

	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {

			visit[i] = true;
			arr[depth] = i;
			dfs(n, m, depth + 1);
			visit[i] = false;
		}
	}
}

void solve() {

	int n, m;
	cin >> n >> m;

	dfs(n, m, 0);
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}