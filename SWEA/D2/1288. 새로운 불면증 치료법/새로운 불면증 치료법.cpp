#include <iostream>
using namespace std;

int checkSheep(int n) {
	int k = 0, check = 0, num = n;
	while (++k) {
		num = k * n;
		while (num) {
			check |= 1 << (num % 10);
			num /= 10;
		}

		if (check == (1 << 10) - 1)
			return k * n;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		int ans = checkSheep(n);
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}
