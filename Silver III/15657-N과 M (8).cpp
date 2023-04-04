#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int input[9];

void dfs(int depth) {

	if (m == depth) {
		for (int i = 0; i < m; i++) {

			cout << arr[i] << " ";
		}
		cout << '\n';
	}

	if (m > depth) {
		for (int i = 0; i < n; i++) {
			if (input[i] >= arr[depth - 1]) {
				
				arr[depth] = input[i];
				dfs(depth + 1);
			}
			
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