#include <iostream>
using namespace std;

int main() {

	int t, h, w, n, f = 1, r = 1;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;

		f = (n % h == 0) ? h : n % h;
		r = (n % h == 0) ? n / h : 1 + n / h;

		if (r < 10)
			cout << f << "0" << r << endl;
		else
			cout << f << r << endl;
	}

	return 0;
}