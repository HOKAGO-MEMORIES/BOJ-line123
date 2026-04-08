#include <iostream>
#include <stack>
using namespace std;

long long solve(int n) {
	long long prev = 0;
	long long ans = 1;

	for (int i = 1; i < n; i++) {
		long long temp = ans;
		ans = ans + prev;
		prev = temp;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
    cin >> n;

    cout << solve(n) << '\n';
}