#include <iostream>
using namespace std;

int main() {

	int a, sum = 0;
	char b[101] = { };
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		sum = sum + b[i] - 48;
	}
	cout << sum << endl;
}