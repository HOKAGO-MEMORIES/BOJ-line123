#include <iostream>
using namespace std;

long long pow(long long a, long long b, long long c) {

	if (b == 0) return 1;
	if (b == 1) return a % c;
	
	long long half = pow(a, b/2, c) % c;
	half = half * half % c;

	if (b % 2) 
		return half * a % c;
	else
		return half;
}

void solve() {

	long long a, b, c;
	cin >> a >> b >> c;

	long long ans = pow(a, b, c);
	cout << ans << '\n';		
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}