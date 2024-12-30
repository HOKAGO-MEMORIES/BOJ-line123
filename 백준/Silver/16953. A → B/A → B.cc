#include <iostream>
using namespace std;

int a, b, cnt = 10001;

void bfs(long long cur, int depth) {

	if (cur == b) 
		cnt = (depth < cnt) ? depth : cnt;

	if (cur < b && depth <= cnt) {
		bfs(cur * 2, depth + 1);
		bfs(cur * 10 + 1, depth + 1);
	}
}

void solve() {
	
	cin >> a >> b;
	bfs(a, 1);

	if (cnt == 10001)
		cnt = -1;

	cout << cnt << '\n';

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}