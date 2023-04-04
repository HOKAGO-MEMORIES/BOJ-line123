#include <iostream>
#include <set>
using namespace std;

void solve() {

	string str;
	cin >> str;

	int len = str.length();
	set<string> s;

	for (int i = 0; i < len; i++) {
		
		int x = 0, y = len - i, cnt = 0;

		while (cnt <= i) {

			string ss = str.substr(x, y);
			s.insert(ss);

			x++;
			cnt++;
		}
	}

	cout << s.size() << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}