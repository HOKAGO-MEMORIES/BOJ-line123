#include <iostream>
using namespace std;

int n;

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = n - i; j < n; j++)
			cout << " ";
		for (int j = i; j < n; j++) 
			cout << "*";
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	solve();

	return 0;
}
