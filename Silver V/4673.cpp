#include <iostream>
using namespace std;
#define ARRAY_SIZE 10000

bool self_Num[ARRAY_SIZE + 1] = { };

void d(int n) {
	if (n <= 10000) {
		self_Num[n - 1] = true;
		int sum = n, a = n, b = 0;

		while (a > 0) {
			b = a % 10;
			a = a / 10;
			sum += b;
		}

		d(sum);
	}
}

int main() {

	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (!self_Num[i]) {
			d(i + 1);
			cout << i + 1 << '\n';
		}
	}

	return 0;
}