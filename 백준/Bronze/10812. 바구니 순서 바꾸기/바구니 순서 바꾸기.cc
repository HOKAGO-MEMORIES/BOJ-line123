#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];

void solve() {

	int n, m, i, j, k;
	cin >> n >> m;

	for (int x = 1; x <= n; x++)
		arr[x] = x;

	while(m--) {

		cin >> i >> j >> k;

		rotate(arr + i, arr + k, arr + j + 1);
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