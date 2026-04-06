#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> s;

int solve() {
	int ans = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;

		while (!s.empty() && y < s.top()) {
			s.pop();
			ans++;
		}

		if (!s.empty() && y == s.top()) continue;

		if (y > 0)	s.push(y);
	}

	
	ans += s.size();
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;

    cout << solve() << '\n';
}