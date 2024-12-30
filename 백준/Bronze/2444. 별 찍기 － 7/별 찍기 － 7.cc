#include <iostream>
using namespace std;

void solve() {

	int n, space, star;
	cin >> n;
	space = n-1;
	star = 1;

	for (int i = 0; i < (2*n-1); i++) {

		for (int j = 0; j < space; j++)
			cout << " ";

		for (int k = 0; k < star; k++) 
			cout << "*";

		if(i >= n - 1) {
			space++;
			star = star - 2;
		}
		else {
			space--;
			star = star + 2;
		}

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