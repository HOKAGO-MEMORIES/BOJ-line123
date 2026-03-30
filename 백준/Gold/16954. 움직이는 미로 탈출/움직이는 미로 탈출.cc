#include <iostream>
#include <string>
#include <queue>
using namespace std;

char graph[8][8];
bool visited[8][8][9];
int dx[] = {0, 1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, 0, -1, 1, -1, 1, -1};

struct State {
    int x, y, t;
};

bool isNotWall(int x, int y, int t) {
    if (x - t >= 0 && graph[x - t][y] == '#') return false;
    if (x - (t + 1) >= 0 && graph[x - (t + 1)][y] == '#') return false;
    return true; 
}

bool isInRange(int x, int y) {
	return (x >= 0 && y >= 0 && x < 8 && y < 8);
}

int solve() {
    queue<State> q;
	q.push({7, 0, 0});
    visited[7][0][0] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
        int t = q.front().t;
		q.pop();

		if ((x == 0 && y == 7) || t >= 8)
			return 1;

        for (int i = 0; i < 9; i++) {
    		int nx = x + dx[i];
	    	int ny = y + dy[i];
			int nt = t + 1;

		    if (isInRange(nx, ny) && isNotWall(nx, ny, t) && !visited[nx][ny][nt]) {
			    visited[nx][ny][nt] = true;
			    q.push({nx, ny, nt});
		    }
	    }

	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i < 8; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < 8; j++) {
			graph[i][j] = input[j];
		}
	}
	
	cout << solve() << '\n';
	return 0;
}
