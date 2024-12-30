#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 101;
const int INF = 123456789;
int graph[MAXN][MAXN];

void solve() {
	int n, m, a, b, c;
	cin >> n >> m;
	
	//그래프 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}

	//그래프 입력
	while(m--) {
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}


	//플로이드-워셜 최단거리찾기
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				//둘 중 한 곳의 값이 INF라면 i에서 j로 갈 수 없음
				if (graph[i][k] == INF || graph[k][j] == INF) continue;
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	//그래프 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == INF)
				cout << 0 << " ";
			else
				cout << graph[i][j] << " ";
		}
		cout << '\n';		
	}
	
}	

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}