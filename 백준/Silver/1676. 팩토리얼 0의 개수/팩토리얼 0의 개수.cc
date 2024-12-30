#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int count = 0, n;

	while (N--) {
		n = N + 1;
		while (n >= 5) {
			if (n % 5 == 0) {
				count++;
				n /= 5;
			}
			else
				break;
		}
	}

	cout << count << '\n';

	return 0;
}