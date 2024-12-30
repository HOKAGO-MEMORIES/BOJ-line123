#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 501;
const int INF = 1e9;
int dist[MAXN];

struct edge {
    int from;
    int to;
    int cost;
};

vector<edge> vc;

void bellmanFord(int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < vc.size(); j++) {
            int from = vc[j].from;
            int to = vc[j].to;
            int cost = vc[j].cost;

            if (dist[from] + cost < dist[to])
                dist[to] = dist[from] + cost;
        }
    }

    for (int j = 0; j < vc.size(); j++) {
        int from = vc[j].from;
        int to = vc[j].to;
        int cost = vc[j].cost;

        if (dist[from] + cost < dist[to]) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

void init(int n) {
    vc.clear();
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
}

void solve() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m, w, s, e, t;
        cin >> n >> m >> w;

        init(n);

        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            vc.push_back({s, e, t});
            vc.push_back({e, s, t});
        }

        for (int j = 0; j < w; j++) {
            cin >> s >> e >> t;
            vc.push_back({s, e, -t});
        }

        bellmanFord(n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
