#include <iostream>
using namespace std;

int Euclidiean(int a, int b) {
	int r = a % b;
	if (r == 0) return b;
	return Euclidiean(b, r);
}

void solve() {

	int t, a, b;
	cin >> t;
	
	while (t--) {

		int gcd = 0, ans = 0;
		cin >> a >> b;

		if(a < b) {
			int temp = b;
			b = a;
			a = temp;
		}

		gcd = Euclidiean(a, b);
		ans = b * (a / gcd);
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