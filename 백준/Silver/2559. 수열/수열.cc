#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int n, int k, vector<int> &vec) {
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += vec[i];
	}

	int ans = sum;

	for (int i = k; i < n; i++) {
		sum += vec[i] - vec[i - k];
		ans = max(sum, ans);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int ans = solve(n, k, vec);
	cout << ans << '\n';

	return 0;
}
