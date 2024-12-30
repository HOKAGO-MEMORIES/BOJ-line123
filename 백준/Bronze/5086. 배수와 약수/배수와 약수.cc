#include <iostream>
using namespace std;

void solve() {

	int x, y;
	
	while (true) {
		cin >> x >> y;
		
		if (x == 0 && y == 0)
			break;

		if (y % x == 0)
			cout << "factor" << '\n';
		else if (x % y == 0)
			cout << "multiple" << '\n';
		else
			cout << "neither" << '\n';
	}


}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}