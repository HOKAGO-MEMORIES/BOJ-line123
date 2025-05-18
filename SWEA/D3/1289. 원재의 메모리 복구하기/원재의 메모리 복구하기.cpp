#include <iostream>
#include <string>
using namespace std;

int checkBit(string s) {
	int ans = 0, len = s.length(), num = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] != num + '0') {
			num = num ? 0 : 1;
			ans++;
		}
	}

	return ans;
}
 
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		cin >> s;

		int ans = checkBit(s);
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}
