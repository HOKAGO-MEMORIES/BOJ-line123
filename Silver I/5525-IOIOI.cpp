#include <iostream>
using namespace std;

void solve() {
	int n, m, count, answer = 0;
	string s;

	cin >> n >> m >> s;
	
	for (int i = 0; i < m; i++) {
		if (s[i] == 'I') {
			count = 0;

			while (i <= m) {

				if (s[i + 1] == 'O' && s[i + 2] == 'I') {
					count++;
				}
				else {
					break;
				}					

				if (count >= n) 
					answer++;

				i += 2;
			}				
		}
	}

	cout << answer << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}