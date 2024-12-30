#include <iostream>
#include <set>
using namespace std;

void solve() {

	int n, m, cnt = 0;
	cin >> n >> m;

	string s;
	set<string> str;

	for (int i = 0; i < n; i++) {
		cin >> s;
		str.insert(s);
	}

	for (int j = 0; j < m; j++) {
		cin >> s;
		
		if (str.find(s) != str.end())
			cnt++;
	}

	cout << cnt << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}