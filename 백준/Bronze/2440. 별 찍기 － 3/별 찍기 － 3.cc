#include <iostream>
using namespace std;

void solve(int n) {
	while(n--) {
		for (int i = 0; i <= n; i++)
			cout << '*';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	solve(n);

	return 0;
}
