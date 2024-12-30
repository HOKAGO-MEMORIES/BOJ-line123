#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 10001;
vector<pair<int, int>> vec[MAXN];
bool visit[MAXN];
int ans = 0, maxNode = 0;

void dfs(int node, int weight) {
	if (visit[node]) return;
	visit[node] = true;

	if (ans < weight) {
		ans = weight;
		maxNode = node;
	}

	for (int i = 0; i < vec[node].size(); i++)
		dfs(vec[node][i].first, weight + vec[node][i].second);
}

void solve() {
	
	int n, parent, child, weight;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> parent >> child >> weight;
		vec[parent].push_back({child, weight});
		vec[child].push_back({parent, weight});
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