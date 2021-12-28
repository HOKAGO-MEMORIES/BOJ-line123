#include <iostream>
using namespace std;

int main() {
	int a, b, n;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		cin >> n;
		if (n < b) cout << n << " ";
	}
	return 0;
}