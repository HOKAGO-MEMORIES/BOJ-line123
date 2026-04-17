#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int result[100001];

void solve() {
	priority_queue<int, vector<int>, greater<int>> computer;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int idx = 0;
	for (int i = 0; i < N; i++) {
		while (!pq.empty() && v[i].first >= pq.top().first) {
			computer.push(pq.top().second);
			pq.pop();
		}
		
		if (computer.empty()) {
			pq.push({ v[i].second, idx });
			result[idx++]++;
		}
		else {
			pq.push({ v[i].second, computer.top() });
			result[computer.top()]++;
			computer.pop();
		}
	}

	cout << idx << '\n';
	for (int i = 0; i < idx; i++)
		cout << result[i] << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	
	solve();
	return 0;
}
