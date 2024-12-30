#include <iostream>
using namespace std;

int n, m;
int arr[8];

void dfs(int depth) {

	if (m == depth) {
		for (int i = 0; i < m; i++) {

			cout << arr[i] << " ";
		}
		cout << '\n';
	}

	if (m > depth) {
		for (int i = 1; i <= n; i++) {
			
			arr[depth] = i;
			dfs(depth + 1);
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