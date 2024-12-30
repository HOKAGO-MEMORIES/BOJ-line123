#include <iostream>
using namespace std;

bool is_not_prime[1000001] = {};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	is_not_prime[0] = true;
	is_not_prime[1] = true;

	for (int i = 2; i < N + 1; i++) {

		for (int j = 2 * i; j <= N + 1; j += i) {
			if(!is_not_prime[j])
				is_not_prime[j] = true;
		}
	}


	for (int k = M; k < N + 1; k++) {
		if (!is_not_prime[k])
			cout << k << '\n';
	}

	return 0;
}