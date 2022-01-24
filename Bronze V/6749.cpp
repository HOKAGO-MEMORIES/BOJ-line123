#include <iostream>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	cout << b + (b - a) << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}