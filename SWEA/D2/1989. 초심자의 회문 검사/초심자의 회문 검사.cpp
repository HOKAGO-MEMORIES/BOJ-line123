#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string s) {
	int len = s.length();
	int left = len / 2 - 1;
	int right = len / 2;

	if (len % 2)
		right++;

	for (int i = 0; i < len / 2; i++) {
		if (s[left] != s[right])
			return false;
		left--;
		right++;
	}

	return true;
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
		
		int ans = checkPalindrome(s);
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}
