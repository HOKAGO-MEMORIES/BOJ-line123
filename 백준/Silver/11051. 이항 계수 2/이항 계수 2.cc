#include <iostream>
using namespace std;

int C[1001][1001];

void solve() {

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			
			if (i == j || j == 0) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 10007;
		}
	}

	cout << C[n][k] << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}