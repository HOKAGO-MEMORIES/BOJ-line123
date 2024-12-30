#include <iostream>
#include <queue>
using namespace std;

int n, sx, sy;
int sz = 2, count, result;
bool eat;

int arr[20][20];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void input() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			cin >> arr[i][j];

			if(arr[i][j] == 9) {
				sx = i;
				sy = j;
				arr[i][j] = 0;
			}
		}
	}
} 

void bfs(int fx, int fy, bool visit[][20]) {
	
	queue<pair<pair<int, int>, int>> q;
	q.push({{fx, fy}, result});
	visit[fx][fy] = true;
	int sturn = 0;
	
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int turn = q.front().second;
		
		q.pop();

		if(arr[x][y] > 0 && arr[x][y] < sz && turn == result) {
		
			if(x < sx || x == sx && y < sy && turn <= sturn) {
				sx = x;
				sy = y;
			}
			
			continue;
		}

		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(!visit[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if(arr[nx][ny] <= sz) {
					
					if(arr[nx][ny] > 0 && arr[nx][ny] < sz && !eat) {
						sx = nx;
						sy = ny;
						sturn = turn + 1;
						result = turn + 1;
						eat = true;
					}
					
					q.push({{nx, ny}, turn + 1});
					visit[nx][ny] = true;
				}
			}

		}

	}
}

void solve() {
	
	input();

	while(true) {
	
		bool visit[20][20] = {false,};

		bfs(sx, sy, visit);

		if(!eat)
			break;
			
		count++;
		arr[sx][sy] = 0;
		eat = false;

		if(sz == count) {
			sz++;
			count = 0;
		}

	}

	cout << result << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}