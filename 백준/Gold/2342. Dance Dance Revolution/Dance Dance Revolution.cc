#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

static int INF = 1e9;
int n, len;
vector<int> v;
int dp[100000][5][5];

int getPower(int from, int to) {
    if (from == 0) return 2;
    else if (from == to) return 1;
    else if (from + 2 == to || from == to + 2) return 4;
    else return 3;
}

// 중 0, 상 1, 좌 2, 하 3, 우 4
int solve(int cnt, int left, int right) {
    if (cnt == len) 
        return 0;

    if (dp[cnt][left][right] != -1)
        return dp[cnt][left][right];

    int moveLeft = solve(cnt + 1, v[cnt], right) + getPower(left, v[cnt]);
    int moveRight = solve(cnt + 1, left, v[cnt]) + getPower(right, v[cnt]);

    return dp[cnt][left][right] = min(moveLeft, moveRight);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (cin >> n && n != 0) 
        v.push_back(n);

    len = v.size();
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0, 0) << '\n';
    return 0;
}
