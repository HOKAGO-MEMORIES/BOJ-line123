#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1001;
const int inf = 987654321;
int dist[2][MAXN];

//vec[0] : x에서 각 마을로 돌아가는데 사용
//vec[1] : 각 마을에서 x로 모이는데 사용
vector<pair<int, int>> vec[2][MAXN];

void dijkstra(int num, int x) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({x, 0});

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (cost > dist[num][cur])
			continue;

		for (int i = 0; i < vec[num][cur].size(); i++) {
			int next = vec[num][cur][i].first;
			int nextCost = cost + vec[num][cur][i].second;

			if (nextCost < dist[num][next]) {
				dist[num][next] = nextCost;
				pq.push({next, nextCost});
			}
		}
	}
}

void solve() {
	int n, m, x, a, b, t;
	//a : 시작점, b : 끝점, t : 소요시간
	cin >> n >> m >> x;

	for (int i = 1; i <= n; i++) {
		dist[0][i] = inf;
		dist[1][i] = inf;
	}

	dist[0][x] = 0;
	dist[1][x] = 0;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> t;
		vec[0][a].push_back({b, t});
		vec[1][b].push_back({a, t});
	}

	dijkstra(0, x);
	dijkstra(1, x);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[0][i] != inf && dist[1][i] != inf)
			ans = max(dist[0][i] + dist[1][i], ans);
	}
		
	cout << ans << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}