#include <iostream>
#include <cmath>
using namespace std;

int t, x_1, y_1, x_2, y_2, n, cx, cy, r;


void solve() {

	cin >> t;

	while (t--) {

		int ans = 0;
		cin >> x_1 >> y_1 >> x_2 >> y_2 >> n;

		while (n--) {

			cin >> cx >> cy >> r;

			if (pow((x_1 - cx), 2) + pow((y_1 - cy), 2) < pow(r, 2)
			^ pow((x_2 - cx), 2) + pow((y_2 - cy), 2) < pow(r, 2))
				ans++;
		}

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