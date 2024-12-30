#include <iostream>
using namespace std;

void solve() {

	int x1, y1, x2, y2, x3, y3, n, m;
		
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	n = (x1 == x2) ? x3 : (x1 == x3) ? x2 : x1; 
	m = (y1 == y2) ? y3 : (y1 == y3) ? y2 : y1; 
	
	cout << n << " " << m << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}