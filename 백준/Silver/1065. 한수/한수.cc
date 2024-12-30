#include <iostream>
using namespace std;

int AP(int n) {
	int count = 0, a = 0, b = 0, c = 0;
	if (n == 1000) n--;

	while (n > 0) {
		if (!(n / 100)) {
			count++;
		}
		else {
			a = n / 100;
			b = n % 100;
			c = b % 10;
			b = b / 10;
			if (b - a == c - b) count++;
		}
		n--;
	}
	return count;
}

int main() {

	int n;
	cin >> n;
	cout << AP(n) << '\n';

	return 0;
}