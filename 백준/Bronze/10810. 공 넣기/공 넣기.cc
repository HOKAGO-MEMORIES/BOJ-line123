#include <iostream>
using namespace std;

int arr[100];

void solve() {

	int n, m, i, j, k;
	cin >> n >> m;

	while(m--) {
		cin >> i >> j >> k;

		for (int x = i; x <= j; x++)
			arr[x] = k;
	}

	for (int y = 1; y <= n; y++)
		cout << arr[y] << " ";
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}