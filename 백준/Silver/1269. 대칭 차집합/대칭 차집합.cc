#include <iostream>
#include <map>
using namespace std;

void solve() {

	int n, m, ans = 0, num = 0;
	cin >> n >> m;
	
	map<int, bool> mp;

	for (int i = 0; i < n + m; i++) {

		cin >> num;
		if (!mp[num]) {
			ans++;
			mp[num] = true;
		}
		else
			ans--;
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