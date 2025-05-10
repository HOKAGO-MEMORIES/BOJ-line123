#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 2)
				ans += i;
			else
				ans -= i;
		}
		
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}
