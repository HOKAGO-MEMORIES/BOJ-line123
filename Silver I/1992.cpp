#include <iostream>
#include <string>
using namespace std;

int arr[64][64];
string answer;

void solve(int x, int y, int m) {
	int first = arr[x][y];
	bool not_equal = false;

	for (int i = x; i < x + m; i++) {
		for (int j = y; j < y + m; j++) {
			if (arr[i][j] != first) {
				not_equal = true;
				break;
			}
		}
		if (not_equal)
			break;
	}

	if (not_equal) {
		answer += '(';

		int half = m / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(x + (half * i), y + (half * j), half);
			}
		}

		answer += ')';
	}
	else {
		answer += to_string(first);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string num = "";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		for (int j = 0; j < n; j++) {
			arr[i][j] = (num[j] - '0');
		}
	}

	solve(0, 0, n);

	cout << answer << '\n';

	return 0;
}