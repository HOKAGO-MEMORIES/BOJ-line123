#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

void solve() {
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<pair<int, int>> vec[20001];
	int dist[20001];
	
	int V, E, K, u, v, w;
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		vec[u].push_back({v, w});
	}

	fill_n(dist, 20001, INF);
	dist[K] = 0;

	pq.push({0, K});

	while(!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost > dist[cur])
			continue;
		
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int nextCost = cost + vec[cur][i].second;

			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				pq.push({nextCost, next});
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) 
			cout << "INF" << '\n';
		else 
			cout << dist[i] << '\n';
	}
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}