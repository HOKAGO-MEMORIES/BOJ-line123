#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
	int n, a, b;
	int xLow = 10000, xHigh = -10000, yLow = 10000, yHigh = -10000;

	cin >> n;
	while (n--) {
		cin >> a >> b;
		xLow = min(a, xLow);
		xHigh = max(a, xHigh);
		yLow = min(b, yLow);
		yHigh = max(b, yHigh);
	}

	cout << (xHigh - xLow) * (yHigh - yLow) << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}