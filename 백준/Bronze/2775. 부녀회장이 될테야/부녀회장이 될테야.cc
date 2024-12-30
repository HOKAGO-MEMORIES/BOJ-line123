#include <iostream>
using namespace std;

int get_room(int k, int n) {
	if (k == 0)
		return n;
	if (n == 1)
		return 1;
	return (get_room(k, n - 1) + get_room(k - 1, n));
}

int main() {

	int t, k, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		int room = get_room(k, n);
		cout << room << endl;
	}

	return 0;
}