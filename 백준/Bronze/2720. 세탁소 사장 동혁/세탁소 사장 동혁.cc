#include <iostream>
using namespace std;

void solve() {

	int t, cent[4] = {25, 10, 5, 1};
	cin >> t;

	while (t--) {

		int c, change[4] = {};
		cin >> c;


		for (int i = 0; i < 4; i++) {
			if (c / cent[i]) {
			change[i] = c / cent[i];
			c -= change[i] * cent[i];
			}
		}
		
		for (int i = 0; i < 4; i++)
			cout << change[i] << " ";
		cout << '\n';
	}
}	

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}