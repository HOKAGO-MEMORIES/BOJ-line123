#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
vector<long long> v;

void solve() {
	sort(v.begin(), v.end());
	for (long long ll : v)
		cout << ll << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		long long ll = stoll(s);
		v.push_back(ll);
	}

	solve();
	return 0;
}
