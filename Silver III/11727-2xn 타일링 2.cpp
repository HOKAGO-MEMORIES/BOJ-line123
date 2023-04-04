#include <iostream>
using namespace std;

void solve() {
	int arr[1001] = {};
	arr[1] = 1;

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0)
			arr[i] = ((arr[i - 1] * 2) + 1) % 10007;
		else
			arr[i] = ((arr[i - 1] * 2) - 1) % 10007;
	}

	cout << arr[n] << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}