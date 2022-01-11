// 문제에 속았었음
#include <iostream>
using namespace std;

void solve() {
	int t;
	cin >> t;

	while (t--) {
		int arr[51] = {};
		int n, answer = 0, max = 0, min = 1000000000;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			max = (max > arr[i]) ? max : arr[i];
			min = (min < arr[i]) ? min : arr[i];
		}
			
		answer = max - min;

		cout << answer << '\n';
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}