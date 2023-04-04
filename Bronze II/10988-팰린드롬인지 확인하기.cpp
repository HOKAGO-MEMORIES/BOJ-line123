#include <iostream>

using namespace std;

void solve() {

	string s;
	cin >> s;
	int len, ans = 1;
	len = s.length() - 1;

	for (int i = 0; i <= (len / 2); i++) {

		if (s[i] != s[len - i])
			ans = 0;
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