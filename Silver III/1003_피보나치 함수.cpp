#include <iostream>
using namespace std;

int arr[41][2] = {};

void fibonacci(int n) {
	if (n == 0) {
		arr[n][0]++;
		return;
	}
	else if (n == 1) {
		arr[n][1]++;
		return;
	}
	else {
		arr[n][0] = arr[n - 1][0] + arr[n - 2][0];
		arr[n][1] = arr[n - 1][1] + arr[n - 2][1];
		return;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 41; i++) 
		fibonacci(i);

	int T;
	cin >> T;

	int N;
	while (T--) {
		cin >> N;
		cout << arr[N][0] << " " << arr[N][1] << '\n';
	}

	return 0;
}