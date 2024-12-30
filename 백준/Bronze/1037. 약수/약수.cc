#include <iostream>
#include <cmath>
using namespace std;

void solve() {

	int t, n, minN = 1000000, maxN = -1;
	cin >> t;

	while (t--) {
		cin >> n;

		minN = (minN < n) ? minN : n;
		maxN = (maxN > n) ? maxN : n;
	}

	cout << minN * maxN << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}