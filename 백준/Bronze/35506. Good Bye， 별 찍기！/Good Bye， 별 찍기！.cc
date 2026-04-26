#include <iostream>
using namespace std;

int n;
bool arr[202][404];

void solve() {
	int idx = n;
	int gap = 2;

	for (int i = 1; i <= 2 * n; i++) {
		arr[i][2 * n - i + 1] = true;
	
		if (i > 1) {
			if (i <= n) {
				idx--;
				gap += 2;
			} else {
				if (i != n + 1) {
					idx++;
					gap -= 2;
				}
					
			}
		}
		
		
		arr[i][2 * n + 1 + idx] = true;
		arr[i][2 * n + 1 + idx + gap] = true;
	}


	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= 4 * n + 2; j++) {
			if (arr[i][j]) cout << '*';
			else cout << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	solve();
	return 0;
}
