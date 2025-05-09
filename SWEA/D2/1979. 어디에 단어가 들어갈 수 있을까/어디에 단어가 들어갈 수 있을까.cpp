#include <iostream>
#include <vector>
using namespace std;

void setPuzzle(int n, vector<vector<int>>& puzzle) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> puzzle[i][j];
	}
}

int checkWord(int n, int k, vector<vector<int>>& puzzle, bool isRow) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			int cell = isRow ? puzzle[i][j] : puzzle[j][i];

			if (cell == 1) {
				cnt++;
				if (cnt > k) cnt = 0;
				if (j == (n - 1) && cnt == k) ans++;
			}
			else {
				if (cnt == k) ans++;
				cnt = 0;
			}
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
		int n, k;
		cin >> n >> k;

		vector<vector<int>> puzzle(n, vector<int>(n, 0));
		setPuzzle(n, puzzle);

		int ans = checkWord(n, k, puzzle, true) + checkWord(n, k, puzzle, false);
		cout << "#" << test_case << " " << ans << '\n';


	}
	return 0;
}
