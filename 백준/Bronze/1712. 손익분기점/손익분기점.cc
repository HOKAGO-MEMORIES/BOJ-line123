#include <iostream>
using namespace std;

double A, B, C;
int ans = 1;

void solve() {
	if(B >= C)
		ans = -1;
	else 
		ans = (int)(A / (C - B)) + 1;
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> A >> B >> C;

	solve();

	cout << ans << '\n';

    return 0;
}