#include <iostream>
using namespace std;

int solve(int n, int m) {
	return n * m - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
    cin >> n >> m;

    cout << solve(n, m) << '\n';
}