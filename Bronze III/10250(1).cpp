#include <iostream>
#include <string>
using namespace std;

int main() {

	int t, h, w, n, f = 1, r = 1;
	string result = "", f_string = "", r_string = "";
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;

		if (n > h) {
			f = (n % h == 0) ? h : n % h;
			r = (n % h == 0) ? n / h : 1 + n / h;
		}
		else {
			f = n;
			r = 1;
		}

		f_string = to_string(f);
		if (r < 10) r_string = to_string(0) + to_string(r);
		else r_string = to_string(r);
		
		result = f_string + r_string + '\n';
		cout << result;
	}

	return 0;
}