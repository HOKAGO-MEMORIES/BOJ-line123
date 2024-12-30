#include <iostream>
using namespace std;

int main() {

	int a, b, c, d, e, f = 0, n = 0;
	cin >> a;
	b = a / 10;
	c = a % 10;
	
	while (true) {
		d = b + c;
		if (d >= 10) e = d % 10;
		else e = d;
		f = (c * 10) + e;
		n++;

		if (a == f) break;

		b = f / 10;
		c = f % 10;
	}

	cout << n;

	return 0;
}