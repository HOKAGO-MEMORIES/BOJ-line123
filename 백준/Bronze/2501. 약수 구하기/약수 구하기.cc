#include <iostream>
using namespace std;

void solve() {

	int n, k, cnt = 0, ans = 0;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		if(n % i == 0) {
			cnt++;

			if (cnt == k) {
				cout << i << '\n';
				break;
			}
		}
	}

	if (cnt < k)
		cout << "0" << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}