#include <iostream>
#include <algorithm>
using namespace std;

int arr[500][500];
bool visit[500][500];
int n, m, result;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input() {

	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
} 

//테트로미노는 회전이나 대칭이 되기 때문에 시작점에서부터 모든 경우의 수를 찾음
void dfs(int x, int y, int sum, int length) {
	
	if(length >= 4) {
		result = max(result, sum);
		return;
	}
	
	for(int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
			if(!visit[next_x][next_y]) {

				visit[next_x][next_y] = true;
				dfs(next_x, next_y, sum + arr[next_x][next_y], length + 1);

				visit[next_x][next_y] = false;
				//기존의 dfs와 다르게 한 번 탐색했던 곳을 다시 방문하는 경우 발생
				//dfs를 다 돌았다면 false로 하여 다른 경우에서 방문할 수 있도록 함
			}
				
		}
	}
}

//t모양 테트로미노는 4개를 이어서 그릴 수 없기 때문에(깊이가 4가 안됨) dfs가 아닌 따로 체크
void check_t(int x, int y) {

	//ㅗ
	if(y >= 0 && y + 2 < m && x - 1 >= 0 && x < n)
		result = max(result, (arr[x][y] + arr[x][y+1] + arr[x-1][y+1] + arr[x][y+2]));

	//ㅜ
	if(y >= 0 && y + 2 < m && x >= 0 && x + 1 < n)
		result = max(result, (arr[x][y] + arr[x][y+1] + arr[x+1][y+1] + arr[x][y+2]));

	//ㅏ
	if(y >= 0 && y + 1 < m && x >= 0 && x + 2 < n)
		result = max(result, (arr[x][y] + arr[x+1][y] + arr[x+1][y+1] + arr[x+2][y]));

	//ㅓ
	if(y >= 0 && y + 1 < m && x + 1 < n && x - 1 >= 0)
		result = max(result, (arr[x][y] + arr[x][y+1] + arr[x-1][y+1] + arr[x+1][y+1]));

}


void solve() {
	
	input();

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {

			visit[i][j] = true;
			dfs(i, j, arr[i][j], 1);

			visit[i][j] = false;
			check_t(i, j);
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