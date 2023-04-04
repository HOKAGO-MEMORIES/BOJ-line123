#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve() {
	int n, x;
	cin >> n;

	while (n--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
		else 
			pq.push({ abs(x), x });
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}