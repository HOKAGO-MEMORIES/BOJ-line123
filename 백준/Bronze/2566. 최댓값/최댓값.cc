#include <iostream>
using namespace std;

int n, x = 1, y = 1, maxN;

void solve() {

	for(int i = 1; i < 10; i++) {
		for(int j = 1; j < 10; j++) {

			cin >> n;
			if(n > maxN) {
				maxN = n;
				x = i;
				y = j;
			}
		}
	}

	cout << maxN << '\n' << x << " " << y << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}