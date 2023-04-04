#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int input[9];
bool visit[10001];

void dfs(int depth) {

	if (m == depth) {
		for (int i = 0; i < m; i++) {

			cout << arr[i] << " ";
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		if (!visit[input[i]]) {

			visit[input[i]] = true;
			arr[depth] = input[i];
			dfs(depth + 1);
			visit[input[i]] = false;
		}
	}
}

void solve() {

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> input[i];

	sort(input, input + n);
	dfs(0);
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}