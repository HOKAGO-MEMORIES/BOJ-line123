#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1001, MAXM = 1000001, INF = 1e9;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int,int>> vec[MAXM];
int dist[MAXN];

void bfs() {
    while (!pq.empty()) {
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
}

void solve() {
    int n, m, from, to, cost, start, end;
    cin >> n >> m;
    
    fill_n(dist, n + 1, INF);
    while (m--) {
        cin >> from >> to >> cost;
        vec[from].push_back({to, cost});
    }

    cin >> start >> end;
    dist[start] = 0;
    pq.push({0, start});
    bfs();

    cout << dist[end] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
