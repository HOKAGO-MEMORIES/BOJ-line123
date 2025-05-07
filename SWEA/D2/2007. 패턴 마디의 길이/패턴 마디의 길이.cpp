#include <iostream>
#include <string>
using namespace std;

int checkWord(string s) {
	int half = 15, ans = 1;

	for (int i = 1; i <= 10; i++) {
		string left = s.substr(half - i, i);
		string right = s.substr(half, i);

		if (left == right)
			return ans;
		ans++;
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
		
		int ans = checkWord(s);
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}
