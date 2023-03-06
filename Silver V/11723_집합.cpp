#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;

	string s;
	int n, bit = 0;

	while (M--) {
		cin >> s;

		if (s == "add") {
			cin >> n;
			bit |= (1 << n);
		}
		else if (s == "remove") {
			cin >> n;
			bit &= ~(1 << n);
		}
		else if (s == "check") {
			cin >> n;
			if (bit & (1 << n))
				cout << "1" << '\n';
			else
				cout << "0" << '\n';

		}
		else if (s == "toggle") {
			cin >> n;
			if (bit & (1 << n))
				bit &= ~(1 << n);
			else
				bit |= (1 << n);
		}
		else if (s == "all") {
			bit |= ~0;

		}
		else if (s == "empty") {
			bit &= 0;
		}
	}


	return 0;
}