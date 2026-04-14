#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, x, y;
vector<int> v[100001];
int pos[100001];
int order[100001];
bool visited[100001];

int solve(int time, int cnt) {	
	if (order[1] != 1)
		return 0;

	queue<int> q;
	q.push(1);
	visited[1] = true;
	int idx = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur != order[idx++])
			return 0;

		for (int nxt : v[cur]) {
			if (!visited[nxt]) {
				visited[nxt] = true;
				q.push(nxt);
			}
		}
	}

	return 1;
}

bool compare(const int& a, const int& b) {
	return pos[a] < pos[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		cin >> order[i];
		pos[order[i]] = i;
	}
		
	for (int i = 1; i <= n; i++) 
		sort(v[i].begin(), v[i].end(), compare);
	
	cout << solve(0, 0) << '\n';
	return 0;
}
