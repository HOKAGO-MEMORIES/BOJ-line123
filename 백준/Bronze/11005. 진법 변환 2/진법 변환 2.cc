#include <iostream>
#include <algorithm>
using namespace std;

void solve() {

	string ans = "";
	int n, B;
	cin >> n >> B;	

	while (n > 0) {
		int tmp = n % B;

		if (tmp < 10) 
			tmp += '0';
		else
			tmp = tmp + 'A' - 10;

		ans += tmp;
		n /= B;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}	

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}