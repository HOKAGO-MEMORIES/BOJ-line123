#include <iostream>
#include <queue>
#include <map>
using namespace std;

void solve() {
	int T, k, num;
	cin >> T;

	char c;
	while (T--) {
		cin >> k;
		priority_queue<int, vector<int>, less<int>> maxq;
		priority_queue<int, vector<int>, greater<int>> minq;
		map<int, int> m;

		while (k--) {
			cin >> c >> num;

			switch(c) {
			case 'I':
				maxq.push(num);
				minq.push(num);
				m[num]++;
				break;

			case 'D':
				if (num == 1) {
					if (!maxq.empty()) {
						m[maxq.top()]--;
						maxq.pop();
					}
				}
				else {
					if (!minq.empty()) {
						m[minq.top()]--;
						minq.pop();
					}
				}

				while (!maxq.empty() && !m[maxq.top()])
					maxq.pop();
				while (!minq.empty() && !m[minq.top()])
					minq.pop();

				break;
			}
		}

		if (maxq.empty())
			cout << "EMPTY" << '\n';
		else
			cout << maxq.top() << " " << minq.top() << '\n';
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}