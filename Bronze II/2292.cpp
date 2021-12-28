#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int ans = 1, next = 1, next_f = 1, next_l = 1;
	while (true) {
		if (next_f <= n && n <= next_l) break;

		next_f = next_f + next;
		next = 6 * ans;
		next_l = next_l + next;
		ans++;
	}

	cout << ans << endl;
	return 0;
}