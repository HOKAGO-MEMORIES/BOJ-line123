#include <iostream>
using namespace std;

int arr[1000001] = {};

void X(int n) {

	if (n == 1) {
		arr[n] = 0;
	}
	else if (n == 2 || n == 3) {
		arr[n] = 1;
	}
	else {
		arr[n] = arr[n - 1];

		if (n % 3 == 0) {
			arr[n] = min(arr[n], arr[n / 3]);
		}
		if (n % 2 == 0) {
			arr[n] = min(arr[n], arr[n / 2]);
		}
		arr[n]++;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		X(i);

	cout << arr[N] << '\n';

	return 0;
}