#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> sum;
vector<vector<int>> dp;

int solve(int train, int car) {
	if (train > 3) return 0;
	if (car + k - 1 > n) return 0;
	if (dp[train][car] != -1) return dp[train][car];

	// 객차를 건너뛴 경우
	int skip = solve(train, car + 1);

	// 객차를 선택한 경우
	int select = (sum[car + k - 1] - sum[car - 1]) + solve(train + 1, car + k);

	return dp[train][car] = max(skip, select);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	sum.resize(n + 1);
	dp.resize(4, vector<int>(n + 1, -1));

	int input;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		sum[i] = sum[i - 1] + input;
	}
	cin >> k;
	
	cout << solve(1, 1) << '\n';
	return 0;
}
