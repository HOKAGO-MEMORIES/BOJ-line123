//7576번 문제와 유사
#include <iostream>
#include <queue>
using namespace std;

//토마토가 들어가 있는 x, y, z값을 클래스로 생성
class tomato {
public:
	int x, y, z;
	tomato(int z, int x, int y) : x(x), y(y), z(z) {}
};

int Box[101][101][101];
queue<tomato> tq;

int m, n, h;
//ripe: 현재 익은 토마토 개수, total: 토마토 전체 개수
int ripe, total;

int bfs() {
	int dx[6] = {1, -1, 0, 0, 0, 0};
	int dy[6] = {0, 0, 1, -1, 0, 0};
	int dz[6] = {0, 0, 0, 0, 1, -1};

	while (!tq.empty()) {
		tomato t = tq.front();
		tq.pop();

		for (int i = 0; i < 6; i++) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			int nz = t.z + dz[i];

			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h && Box[nz][nx][ny] == 0) {
				//배열에 (토마토가 익은날 + 1) 값을 넣어줌
				Box[nz][nx][ny] = Box[t.z][t.x][t.y] + 1;
				tq.push(tomato(nz, nx, ny));
				ripe++;
			}
		}
	}

	if (total == ripe) {
		int day = 1;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (Box[i][j][k] > day)
						day = Box[i][j][k];
				}
			}
		}
		return day - 1;
	}
	else
		return -1;
}

void solve() {
	cin >> m >> n >> h;
	total = m * n * h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> Box[i][j][k];

				if (Box[i][j][k] == 1) {
					tq.push(tomato(i, j, k));
					ripe++;
				}
				else if (Box[i][j][k] == -1)
					total--;
			}
		}
	}

	//total과 ripe가 동일하다면 이미 전부 다 익었다는 뜻
	if (total == ripe) 
		cout << "0" << '\n';
	else 
		cout << bfs() << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}