#include <iostream>
using namespace std;

bool paper[100][100];
int t, x, y, ans;

void solve() {
	
	cin >> t;

	while (t--) {

		cin >> x >> y;

		for (int i = y; i < y + 10; i++) {
			for (int j = x; j < x + 10; j++) {

				if(!paper[i][j]) {
					paper[i][j] = true;
					ans++;
				}
			}
		}
	}

	cout << ans << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}