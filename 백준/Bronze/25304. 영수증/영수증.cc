#include <iostream>
using namespace std;

int x, n, a, b, total;

void input() {
	cin >> x >> n;

	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		total = total + a * b;
	}
} 

void solve() {
	
	if(x == total)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
		
}


int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	input();

	solve();

    return 0;
}