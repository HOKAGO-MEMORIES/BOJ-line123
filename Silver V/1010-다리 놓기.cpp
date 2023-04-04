#include <iostream>
using namespace std;

int C[30][30];

void solve() {

	int t, n, m;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				
				if (i == j || j == 0) 
					C[i][j] = 1;
				else
					C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}

		cout << C[m][n] << '\n';
	}

}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}