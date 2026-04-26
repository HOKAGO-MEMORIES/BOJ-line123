#include <iostream>
#include <string>
using namespace std;

string s;
int c[26];

void solve() {
	for (char ch : s) 
		c[ch - 'a']++;

	for (int i = 0; i < 26; i++)
		cout << c[i] << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	solve();

	return 0;
}
