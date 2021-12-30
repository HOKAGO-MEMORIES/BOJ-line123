#include <iostream>
using namespace std;

bool is_prime(int n) {
	if (n > 1) {
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				if (n == i) return true;
				else return false;
			}
		}
	}
	else {
		return false;
	}
	return true;
}

int main() {

	int N;
	cin >> N;

	int num;
	int prime = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (is_prime(num)) {
			prime++;
		}
	}

	cout << prime << '\n';
	return 0;
}