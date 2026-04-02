#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
pair<int, int> start_door, end_door;
vector<string> room;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Node {
    int x, y, dir, cnt;
};

int solve() {
    int dist[50][50][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = 1e9;
            }
        }
    }

    queue<Node> q;
    for (int i = 0; i < 4; i++) {
        q.push({start_door.first, start_door.second, i, 0});
        dist[start_door.first][start_door.second][i] = 0;
    }

    int ans = 1e9;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == end_door.first && cur.y == end_door.second) {
            ans = min(ans, cur.cnt);
            continue;
        }

        if (dist[cur.x][cur.y][cur.dir] < cur.cnt) continue;

        int nx = cur.x + dx[cur.dir];
        int ny = cur.y + dy[cur.dir];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n && room[nx][ny] != '*') {
            if (dist[nx][ny][cur.dir] > cur.cnt) {
                dist[nx][ny][cur.dir] = cur.cnt;
                q.push({nx, ny, cur.dir, cur.cnt});
            }
        }


        if (room[cur.x][cur.y] == '!') {
            int ndir1 = (cur.dir + 1) % 4;
            int ndir2 = (cur.dir + 3) % 4;

            if (dist[cur.x][cur.y][ndir1] > cur.cnt + 1) {
                dist[cur.x][cur.y][ndir1] = cur.cnt + 1;
                q.push({cur.x, cur.y, ndir1, cur.cnt + 1});
            }
            if (dist[cur.x][cur.y][ndir2] > cur.cnt + 1) {
                dist[cur.x][cur.y][ndir2] = cur.cnt + 1;
                q.push({cur.x, cur.y, ndir2, cur.cnt + 1});
            }
        }

    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    room.resize(n);
    bool has_start = false;

    for (int i = 0; i < n; i++) {
        cin >> room[i];
        for (int j = 0; j < n; j++) {
            if (room[i][j] == '#') {
                if (has_start) {
                    end_door = make_pair(i, j);
                } else {
                    has_start = true;
                    start_door = make_pair(i, j);
                }
            }
        }
    }

    cout << solve() << '\n';
    return 0;
}
