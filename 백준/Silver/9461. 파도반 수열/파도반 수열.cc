#include <iostream>
using namespace std;

void solve() {
	int t, n;
	cin >> t;

	long long arr[101] = {};
	arr[0] = arr[1] = arr[2] = 1;
	arr[3] = arr[4] = 2;

	for (int i = 5; i < 101; i++)
		arr[i] = arr[i - 5] + arr[i - 1];

	while (t--) {
		cin >> n;
		cout << arr[n - 1] << '\n';
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}