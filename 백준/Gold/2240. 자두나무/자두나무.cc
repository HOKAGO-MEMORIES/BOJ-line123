#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t, w;
int tree[1001];
int dp[1001][31];

int solve(int time, int cnt) {	
	if (time == t) 
		return 0;

	if (dp[time][cnt] != -1) 
		return dp[time][cnt];

	int cur = (cnt % 2 == 0) ? 1 : 2;
	int next = 3 - cur;

	int stay = solve(time + 1, cnt) + (cur == tree[time] ? 1 : 0);

	int move = 0;
	if (cnt < w)
		move = solve(time + 1, cnt + 1) + (next == tree[time] ? 1 : 0);
	
	return dp[time][cnt] = max(stay, move);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t >> w;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < t; i++)
		cin >> tree[i];

	cout << solve(0, 0) << '\n';
	return 0;
}