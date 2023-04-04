#include <iostream>
using namespace std;

int main() {

	int tone[8] = {};
	string ans = {};
	for (int i = 0; i < 8; i++)
		cin >> tone[i];

	for (int j = 0; j < 7; j++) {
		int cal = tone[j + 1] - tone[j];

		if (cal == 1 || cal == -1) {

			if (j == 6 && cal == 1)
				ans = "ascending";
			else if (j == 6 && cal == -1)
				ans = "descending";
		}
		else {
			ans = "mixed";
			break;
		}
	}

	cout << ans << endl;
	return 0;
}