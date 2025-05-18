#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
bool isPalindrome(int len, string& temp) {
	int end = len - 1;
	for (int i = 0; i < len; ++i) {
		if (temp[i] != temp[end - i])	return false;
	}
	return true;
}

int checkWord(vector<string>& board) {
	for (int len = 100; len > 0; --len) {
		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j <= 100 - len; ++j) {
				string row = board[i].substr(j, len);
				if (isPalindrome(len, row))	return len;
			}
		}

		for (int j = 0; j < 100; ++j) {
			for (int i = 0; i <= 100 - len; ++i) {
				string col = "";
				for (int k = 0; k < len; ++k)	col += board[i + k][j];
				if (isPalindrome(len, col))	return len;
			}
		}
	}

	return 1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int caseNum;
		cin >> caseNum;

		vector<string> board(100);
		for (int i = 0; i < 100; ++i)
			cin >> board[i];

		int ans = checkWord(board);
		cout << "#" << caseNum << " " << ans << '\n';
	}
	return 0;
}
