#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int sum = i, num = i, m = 0;
		
		while (num > 0) {
			m = num % 10;
			num = num / 10;
			sum += m;
		}

		if (sum == n) {
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;
	return 0;
}