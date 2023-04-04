#include <iostream>
#include <map>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	map<string, string> mp;
	string a, b;
	while (n--) {
		cin >> a >> b;
		mp.insert(make_pair(a, b));
	}

	while (m--) {
		cin >> a;
		cout << mp[a] << '\n';
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}