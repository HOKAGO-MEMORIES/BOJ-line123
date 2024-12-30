#include <iostream>
using namespace std;

int n;

void printStar(int i, int j, int n) {
	
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << " ";

	else {
		if (n < 3)
			cout << "*";
		else
			printStar(i, j, n / 3);
	}

}

void solve() {
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printStar(i, j, n);

		cout << '\n';
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}