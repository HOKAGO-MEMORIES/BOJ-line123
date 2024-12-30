#include <iostream>
using namespace std;

void solve() {

	int t, len;
	string s;
	cin >> t;

	while(t--) {
		
		cin >> s;
		len = s.length();

		if (len == 1)
			cout << s << s << '\n';
		else
			cout << s[0] << s[len - 1] << '\n';
	}

}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}