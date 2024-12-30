#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 100001;
int ans = 0, maxNode = 0;
vector<pair<int, int>> vec[MAXN];
bool visit[MAXN];

void dfs(int node, int weight) {
    if (visit[node])
        return;

    visit[node] = true;
    
    if (ans < weight) {
        ans = weight;
        maxNode = node;
    }

    for (int i = 0; i < vec[node].size(); i++)
        dfs(vec[node][i].first, weight + vec[node][i].second);
}

void solve() {
    int V;
    cin >> V;

    for (int i = 0; i < V; i++) {
        int node = 0, num = 0, weight = 0;
        cin >> node;

        while (true) {
            cin >> num;
            if (num == -1)
                break;
        
            cin >> weight;
            vec[node].push_back({num, weight});
            vec[num].push_back({node, weight});
        }
    }

    dfs(1, 0);
    ans = 0;
    memset(visit, false, sizeof(visit));

    dfs(maxNode, 0);
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
