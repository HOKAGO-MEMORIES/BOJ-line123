#include <iostream>
#include <queue>
using namespace std;

int map[101];
int dist[101];
queue<int> q;

void bfs() {
    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = now + i;

            if (next > 100)
                continue;

            if (map[next])
                next = map[next];
            
            if (!dist[next]) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
}

void solve() {
    int n, m, start, end, total;
    cin >> n >> m;
    total = n + m;

    while(total--) {
        cin >> start >> end;
        map[start] = end;
    }

    q.push(1);
    bfs();

    cout << dist[100] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
