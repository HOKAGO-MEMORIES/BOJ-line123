#include <iostream>
using namespace std;

int sum, nmin = -1, m, n;

bool isPrime(int i) {

	for (int j = 2; j * j <= i; j++) {
			
		if (i % j == 0) {
			if(i == j) 
				return true;
			return false;
		}
	}
	return true;	
}

void solve() {

	if (m == 1) m++;

	for (int i = m; i <= n; i++) {
		
		if(isPrime(i)) {

			if(nmin < 0) 
				nmin = i;
				
			sum = sum + i;
		}
	}
	
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> m >> n;

	solve();

	if (nmin > 0)
		cout << sum << '\n' << nmin << '\n';
	else
		cout << nmin << '\n';

    return 0;
}