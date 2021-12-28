#include <iostream>
using namespace std;

int main() {

	long long L;
	cin >> L;

	string alphabet;
	cin >> alphabet;

	long long answer = 0;
	long long r = 31;
	long long M = 1234567891;

	for (int i = 0; i < L; i++) {

		char a_char = alphabet[i];
		int a_int = a_char - 'a' + 1;

		for (int j = 0; j < i; j++) 
			a_int = (a_int * r) % M;

		answer = (answer + a_int) % M;
	}

	cout << answer << endl;
	return 0;
}