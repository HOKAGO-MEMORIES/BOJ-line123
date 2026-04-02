#include <iostream>
#include <cmath>
using namespace std;

long long n;
int k, q;

long long getParent(long long x) {
	return (x - 2) / k + 1;
}

long long solve(long long x, long long y) {
	if (k == 1) return abs(x - y);

	long long ans = 0;
	while (x != y) {
		if (x > y) x = getParent(x);
		else y = getParent(y);
		ans++;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k >> q;

	long long x, y;
	while (q--) {
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}
	
	return 0;
}
