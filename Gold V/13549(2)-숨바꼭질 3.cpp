//0-1 너비우선탐색
//가중치가 0이라면 덱 앞쪽으로 삽입, 1이라면 덱 뒤쪽으로 삽입
#include <iostream>
#include <deque>
using namespace std;

const int MAX_N = 100000;
bool visit[MAX_N + 1];

void solve() {
	deque<pair<int, int>> dq;
	int n, k;
	cin >> n >> k;

	dq.push_back({0, n});

	while(!dq.empty()) {
		int time = dq.front().first;
		int X = dq.front().second;
		dq.pop_front();
		visit[X] = true;

		if (X == k) {
			cout << time << '\n';
			break;
		}

		if (X + 1 <= MAX_N && !visit[X + 1])
			dq.push_back({time + 1, X + 1});
		
		if (X - 1 >= 0 && !visit[X - 1])
			dq.push_back({time + 1, X - 1});
		
		if (X * 2 <= MAX_N && !visit[X * 2])
			dq.push_front({time, X * 2});

	}
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}