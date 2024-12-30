#include <iostream>
#include <cmath>
using namespace std;

void solve() {
	int n, point = 2, num = 1, ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		point += num;
		num *= 2;
	}

	ans = pow(point, 2);
	cout << ans << '\n';
}	

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}