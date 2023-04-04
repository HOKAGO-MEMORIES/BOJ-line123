#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100001;
int arr[2][MAX];

void solve() {

	int t, n;
	cin >> t;

	while (t--) {

		cin >> n;
		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < 2; i++) 
			for (int j = 1; j <= n; j++)
				cin >> arr[i][j];

		for (int i = 2; i <= n; i++) {
			arr[0][i] = max(arr[1][i - 1], arr[1][i - 2]) + arr[0][i];
			arr[1][i] = max(arr[0][i - 1], arr[0][i - 2]) + arr[1][i];
		}

		int ans = max(arr[0][n], arr[1][n]);
		cout << ans << '\n';
	}
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}