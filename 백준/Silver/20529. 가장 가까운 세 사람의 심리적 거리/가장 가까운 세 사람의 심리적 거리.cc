#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int checkMBTI(string s1, string s2) {
	int dis = 0;

	for (int i = 0; i < 4; i++) 
		if (s1[i] != s2[i]) dis++;

	return dis;
}

void solve() {
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		vector<string> v;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}

		int ans = 100;

		if (n > 33) 
			ans = 0;
		else {
			for (int i = 0; i < n - 2; i++) {
				for (int j = i + 1; j < n - 1; j++) {
					for (int k = j + 1; k < n; k++) {

						int tmp = checkMBTI(v[i], v[j]) + checkMBTI(v[j], v[k]) + checkMBTI(v[k], v[i]);
						ans = min(ans, tmp);
					}
				}
			}
		}

		cout << ans << '\n';
		
	}
		
}

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}