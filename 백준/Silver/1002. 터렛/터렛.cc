#include <iostream>
#include <cmath>
using namespace std;

void solve() {
	
	int t, r1, r2, ans;
	double x1, y1, x2, y2, distance;
	cin >> t;

	while (t--) {

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		ans = 0;
		distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		if (distance == 0) {
			if (r1 == r2)
				ans = -1;
			else
				ans = 0;
		}
		else {
			
			if (distance == (r1 + r2) || distance == abs(r2 - r1))
				ans = 1;

			else if (distance < (r1 + r2) && distance > abs(r2 - r1))
				ans = 2;

			else 
				ans = 0;
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