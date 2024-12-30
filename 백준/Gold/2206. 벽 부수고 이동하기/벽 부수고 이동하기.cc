#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1001;
int n, m;
int arr[MAXN][MAXN];
int visit[MAXN][MAXN][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

struct pos{
    int x;
    int y;
    int breakWall;
};

int bfs() {
    queue<pos> q;
    q.push({1, 1, 0});
    visit[1][1][0] = 1;

    while(!q.empty()) {
        pos curP = q.front();
        q.pop();

        if (curP.x == n && curP.y == m)
            return visit[curP.x][curP.y][curP.breakWall];
        
        for (int i = 0; i < 4; i++) {
            pos nxt;
            nxt.x = curP.x + dx[i];
            nxt.y = curP.y + dy[i];
            nxt.breakWall = curP.breakWall;

            if (nxt.x < 1 || nxt.x > n || nxt.y < 1 || nxt.y > m)
                continue;

            if (visit[nxt.x][nxt.y][nxt.breakWall])
                continue;

            if (arr[nxt.x][nxt.y] && nxt.breakWall)
                continue;
            else {
                if (arr[nxt.x][nxt.y])
                    nxt.breakWall++;

                visit[nxt.x][nxt.y][nxt.breakWall] = visit[curP.x][curP.y][curP.breakWall] + 1;
                q.push(nxt);
            }
        }
    }

    return -1;
}

void solve() {
    cin >> n >> m;
    string s;

    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++)
            arr[i][j] = s[j - 1] - '0';
    }

    cout << bfs() << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
