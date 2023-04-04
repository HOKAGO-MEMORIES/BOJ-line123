#include <iostream>
using namespace std;

int GCD(int a, int b) {
	int r = a % b;
	if (r == 0) return b;
	return GCD(b, r);
}

void solve() {

	int n, oneRing, theotherRing;
	cin >> n >> oneRing;
	n--;

	while (n--) {
		cin >> theotherRing;
		int gcd = GCD(oneRing, theotherRing);
		
		cout << (oneRing / gcd) << "/" << (theotherRing / gcd) << '\n';
	}
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}