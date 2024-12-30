#include <iostream>
using namespace std;

int n, i = 2;

void solve() {
	while(n > 1) {
		if((i == 2 || i % 2 != 0) && n % i == 0) {
			cout << i << '\n';
			n = n / i;

		} else {
			i++;
		}
	}
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> n;

	if(n != 1)
		solve();

    return 0;
}