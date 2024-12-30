#include <iostream>
using namespace std;

int arr[100001];
int sum[100001];

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	int s, e, answer = 0;
	while (m--) {
		cin >> s >> e;
		if (s == e)
			answer = arr[s];
		else
			answer = sum[e] - sum[s - 1];

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