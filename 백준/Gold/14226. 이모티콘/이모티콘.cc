#include <iostream>
#include <queue>
using namespace std;

bool visited[1001][1001];

void solve(int S) {
	queue<pair<int , pair<int, int>>> q;
	q.push(make_pair(0, make_pair(1, 0)));
		
	visited[0][1] = true;

	while (!q.empty()) {
		int clipboard = q.front().first;
		int sum = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (sum == S) {
			cout << cnt << '\n';
			return;
		}

		if (sum > 0 && sum <= 1000 && !visited[sum][sum]) {
			visited[sum][sum] = true;
			q.push(make_pair(sum, make_pair(sum, cnt + 1)));
		}
			
		if (clipboard > 0 && sum + clipboard <= 1000 && !visited[clipboard][sum + clipboard]) {
			visited[clipboard][sum + clipboard] = true;
			q.push(make_pair(clipboard, make_pair(sum + clipboard, cnt + 1)));
		}
			
		if (sum > 0 && !visited[clipboard][sum - 1]) {
			visited[clipboard][sum - 1] = true;
			q.push(make_pair(clipboard, make_pair(sum - 1, cnt + 1)));
		}
			
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S = 0;
	cin >> S;
	solve(S);

	return 0;
}