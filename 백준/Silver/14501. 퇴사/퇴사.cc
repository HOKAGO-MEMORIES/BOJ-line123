#include <iostream>
#include <algorithm>
using namespace std;

int arr[21][2];
int dp[21];

void solve() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 0; i < N; i++) {
        if (i > 0) dp[i] = max(dp[i - 1], dp[i]);
        int next = i + arr[i][0];
        if (next <= N)
            dp[next] = max(dp[next], dp[i] + arr[i][1]);
    }
        
    cout << *max_element(dp, dp + N + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
