#include <iostream>
using namespace std;

int n;

int solve() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int num = i;
		while (num > 0) {
			int tmp = num % 10;
			if (tmp == 3 || tmp == 6 || tmp == 9)
				ans++;
			num /= 10;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	cout << solve() << '\n';
}