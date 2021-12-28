#include <iostream>

using namespace std;

int main() {


	int max = -1000000;
	int count = 0;
	int input;

	for (int i = 0; i < 9; i++) {
		cin >> input;

		if (input > max) {
			max = input;
			count = i + 1;
		}
	}

	cout << max << '\n' << count << '\n';
	return 0;
}