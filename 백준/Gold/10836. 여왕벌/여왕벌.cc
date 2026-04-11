#include <iostream>
using namespace std;

int m, n;
int sum[1400];

void solve() {
	fill(sum, sum + 1400, 1);
	
	for (int day = 0; day < n; day++) {
		int zero, one, two;
		cin >> zero >> one >> two;

		int idx = zero;
		for (int i = 0; i < one; i++)
			sum[idx++]++;

		for (int i = 0; i < two; i++)
			sum[idx++] += 2;
	}


	for (int i = 0; i < m; i++) {
		cout << sum[m - 1 - i] << " ";
		for (int j = m; j < 2 * m - 1; j++) 
			cout << sum[j] << " ";
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	solve();
}