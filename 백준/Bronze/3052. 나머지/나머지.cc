#include <iostream>

using namespace std;

int main() {

	int arr[42] = { };

	int count = 0;

	int n;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		arr[n % 42]++;
	}

	for (int check : arr) {
		if (check) count++;
	}

	cout << count << '\n';
	return 0;

}