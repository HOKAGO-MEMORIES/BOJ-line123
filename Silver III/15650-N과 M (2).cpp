#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visit[9];

void dfs(int depth) {

	if (depth == m) {

		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}

		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i] && i > arr[depth - 1]) {

			visit[i] = true;
			arr[depth] = i;
			dfs(depth + 1);
			visit[i] = false;
		}
	}
}

void solve() {

	cin >> n >> m;
	dfs(0);
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}