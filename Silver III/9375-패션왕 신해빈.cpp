#include <iostream>
#include <map>
using namespace std;

void solve() {
	int t, n;
	cin >> t;

	while (t--) {
		map<string, int> mp;
		cin >> n;

		string name, type;
		for (int i = 0; i < n; i++) {
			cin >> name >> type;
			if (mp.find(type) != mp.end()) 
				mp[type]++;
			else 
				mp.insert(make_pair(type, 1));
		}

		int answer = 1;
		for (auto k : mp) 
			answer *= (k.second + 1);
		answer--;
		
		cout << answer << '\n';
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}