#include <iostream>

using namespace std;

int main() {

	int input[10] = { };
	int output[10] = { };
	int num = 0;
	int count = 0;

	for (int i = 0; i < 10; i++) {
		cin >> input[i];
		num = input[i] % 42;
		output[i] = num;
	}

	for (int i = 0; i < 10; i++) {
		int result = 0;
		for (int j = i + 1; j < 10; j++) {
			if (output[i] == output[j]) result++;
		}
		if (result == 0) count++;
	}

	cout << count << '\n';
	return 0;

}