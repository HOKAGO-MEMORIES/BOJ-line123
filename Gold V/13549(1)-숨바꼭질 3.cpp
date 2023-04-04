//다익스트라 알고리즘
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 100000;
bool visit[MAX_N + 1];

void solve() {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int n, k;
	cin >> n >> k;

	pq.push({0, n});
	visit[n] = true;

	while(!pq.empty()) {

		int time = pq.top().first;
		int X = pq.top().second;
		pq.pop();
		visit[X] = true;

		if (X == k) {
			cout << time << '\n';
			break;
		}

		if (X + 1 <= MAX_N && !visit[X + 1]) 
			pq.push({time + 1, X + 1});

		if (X - 1 >= 0 && !visit[X - 1]) 
			pq.push({time + 1, X - 1});
 
		if (X * 2 <= MAX_N && !visit[X * 2]) 
			pq.push({time, X * 2});
		
	}
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}