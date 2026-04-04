#include <iostream>
#include <algorithm>
using namespace std;

int arr[9], ans[7];

bool solve(int cnt, int idx, int sum) {
	if (cnt == 7) {
		if (sum == 100) return true;
		else return false;
	}

	if (idx >= 9) return false;

	ans[cnt] = idx;
	if (solve(cnt + 1, idx + 1, sum + arr[idx])) return true;
	if (solve(cnt, idx + 1, sum)) return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	
	sort(arr, arr + 9);
	solve(0, 0, 0);

	for (int n : ans) {
		cout << arr[n] << '\n';
	}

	return 0;
}
