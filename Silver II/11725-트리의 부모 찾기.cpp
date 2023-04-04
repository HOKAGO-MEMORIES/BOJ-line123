#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;
vector<int> vec[MAX + 1];
bool visited[MAX + 1];
int parent[MAX + 1];

void dfs(int node) {
	visited[node] = true;

	for (int i = 0; i < vec[node].size(); i++) {
		
		int num = vec[node][i];

		if (!visited[num]) {
			parent[num] = node;
			dfs(num);
		}
	}
}

void solve() {

	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) 
		cout << parent[i] << '\n';
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}