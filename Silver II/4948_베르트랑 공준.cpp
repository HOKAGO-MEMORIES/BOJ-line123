#include <iostream>
using namespace std;

int n, m, ans;

bool isPrime(int i) {

	for(int j = 2; j * j <= m; j++) {
			
		if(i % j == 0) {
			if(i == j) return true;
			return false;
		}
	}
	return true;
}

void solve() {

	while(true) {
		
		cin >> n;

		if(n == 0) break;
		
		m = 2 * n;
		ans = 0;

		for(int i = n + 1; i <= m; i++) 
			if(isPrime(i)) ans++;
			
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