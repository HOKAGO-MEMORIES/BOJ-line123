#include <iostream>
using namespace std;

int t, n, l, r;
string s;

int recursion(int l, int r) {
	n++;
	if (l >= r) return 1;
	if (s[l] != s[r]) return 0;
	return recursion(l + 1, r - 1);
}

int isPalindrome() {
	return recursion(0, s.length() - 1);
}
 
void solve() {
	
	cin >> t;

	while (t--) {
		
		cin >> s;
		n = 0;

		cout << isPalindrome() << " " << n << '\n';
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}