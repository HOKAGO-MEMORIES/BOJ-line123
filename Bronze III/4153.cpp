#include <iostream>
using namespace std;

int main() {

	int a, b, c, temp = 0;

	while (true) {

		cin >> a >> b >> c;
		
		if (a == 0 && b == 0 && c == 0) break;

		if (a > b) {
			temp = b;
			b = a;
			a = temp;
		}
		if (b > c) {
			temp = c;
			c = b;
			b = temp;
		}

		if (c * c == (a * a + b * b)) cout << "right\n";
		else cout << "wrong\n";
	}

	return 0;
}