#include <iostream>
#include <cstring>
using namespace std;

int arr[51][51];
bool check[51][51];
int M, N;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve(int k, int l) {
	check[k][l] = true;

	for (int i = 0; i < 4; i++) {
		int next_x = k + dx[i];
		int next_y = l + dy[i];
		if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N) {
			if (arr[next_x][next_y] && !check[next_x][next_y]) {
				solve(next_x, next_y);
			}
		}
	}
	
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, K, X, Y;
	cin >> T;

	while (T--) {
		cin >> M >> N >> K;

		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(check));

		while (K--) {
			cin >> X >> Y;
			arr[X][Y] = 1;
		}

		int answer = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] && !check[i][j]) {
					solve(i, j);
					answer++;
				}
			}
		}

		cout << answer << '\n';
	}

	return 0;
}