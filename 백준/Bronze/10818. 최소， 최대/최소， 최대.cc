#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);

	int min = 1000000;
	int max = -1000000;
	int n = 0;
	cin >> n;

	int input;

	for (int i = 0; i < n; i++) {
		cin >> input;

		max = (max > input) ? max : input;
		min = (min < input) ? min : input;
	}

	cout << min << " " << max << '\n';
}