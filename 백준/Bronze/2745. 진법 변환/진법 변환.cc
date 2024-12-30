#include <iostream>
#include <cmath>
using namespace std;

void solve() {

	string n;
	int ans = 0, B;
	cin >> n >> B;	

	int len = n.length() - 1;
	for (int i = 0; i <= len; i++) {

		int num = n[len - i];
		if (num >= 'A') 
			num = num - 'A' + 10;
		else
			num -= '0';
		
		num *= pow(B, i);
		ans += num;	
	}

	cout << ans << '\n';
}	

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}