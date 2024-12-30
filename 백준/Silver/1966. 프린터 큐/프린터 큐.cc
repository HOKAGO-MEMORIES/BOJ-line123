#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;

	int N, M, n;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		queue<pair<int, int>> q;
		priority_queue<int> p;
		int num = 0;

		for (int j = 0; j < N; j++) {
			cin >> n;
			q.push({ j, n });
			p.push(n);
		}

		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();

			if (p.top() == b) {
				num++;
				p.pop();
				if (a == M) {
					cout << num << '\n';
					break;
				}
			}
			else 
				q.push({ a, b });
		}

	}

	return 0;
}