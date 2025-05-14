#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(int n, string& temp) {
	int end = n - 1;
	for (int i = 0; i < n / 2; i++) {
		if (temp[i] != temp[end])
			return false;
		end--;
	}
	return true;
}

int checkWord(int n, vector<string>& board) {
	int ans = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8 - (n - 1); j++) {
			string temp = board[i].substr(j, n);
			if (isPalindrome(n, temp))
				ans++;
		}
	}

	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8 - (n - 1); i++) {
			string temp = "";
			for (int k = 0; k < n; k++) {
				temp += board[i + k][j];
			}
			if (isPalindrome(n, temp))
				ans++;
		}
	}

	return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n = 0;
		cin >> n;

		vector<string> board(8);
		for (int i = 0; i < 8; i++)
			cin >> board[i];

		int ans = checkWord(n, board);
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}