#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int input[9];
int arr[9];
bool visit[9];

void dfs(int depth) {

	if (depth == m) {
		for (int i = 0; i < m; i++) {

			cout << arr[i] << " ";
		}
		cout << '\n';
	}

	int before = 0;

	for (int i = 0; i < n; i++) {
		if (!visit[i] && before != input[i]) {

			before = input[i];
			arr[depth] = input[i];
			visit[i] = true;
			dfs(depth + 1);
			visit[i] = false;
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