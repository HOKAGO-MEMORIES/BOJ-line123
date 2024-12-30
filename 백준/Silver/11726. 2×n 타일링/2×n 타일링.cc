#include <iostream>
using namespace std;

int arr[1001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	arr[0] = 1;
	arr[1] = 2;

	for (int i = 2; i < n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}

	cout << arr[n - 1] << '\n';

	return 0;
}