#include <iostream>
using namespace std;

int t;

bool isPrime(int n) {

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			if (n == i) return true;
			else return false;
		}
	}

	return true;
}

void solve() {

	int n, c1, c2;

	while (t--) {

		cin >> n;
		c2 = n / 2;
		c1 = c2;

		while (true) {


			if (isPrime(c1) && isPrime(c2)) 
				break;
				
			c2++;
			c1--;
		}
		
		cout << c1 << " " << c2 << '\n';

	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	solve();

	return 0;
}