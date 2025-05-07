#include <iostream>
#include <vector>
using namespace std;

bool checkZero(vector<int>& visited) {
	for (int i = 1; i <= 9; i++) {
		if (visited[i] == 0)
			return false;
	}
	return true;
}

bool validateRow(vector<vector<int>>& sudoku) {
	for (int i = 1; i <= 9; i++) {
		vector<int> visited(10, 0);

		for (int j = 1; j <= 9; j++) {
			if (visited[sudoku[i][j]] > 1)
				return false;

			visited[sudoku[i][j]]++;
		}
		if (!checkZero(visited))
			return false;
	}
	return true;
}

bool validateColumn(vector<vector<int>>& sudoku) {
	for (int j = 1; j <= 9; j++) {
		vector<int> visited(10, 0);

		for (int i = 1; i <= 9; i++) {
			if (visited[sudoku[i][j]] > 1)
				return false;

			visited[sudoku[i][j]]++;
		}
		if (!checkZero(visited))
			return false;
	}
	return true;
}

bool validateSubgrid(vector<vector<int>>& sudoku) {
	for (int x = 0; x < 9; x = x + 3) {
		for (int y = 0; y < 9; y = y + 3) {
			vector<int> visited(10, 0);

			for (int i = 1 + x; i <= 3 + x; i++) {
				for (int j = 1 + y; j <= 3 + y; j++) {
					if (visited[sudoku[i][j]] > 1)
						return false;

					visited[sudoku[i][j]]++;
				}
			}
			if (!checkZero(visited))
				return false;
		}
	}
	return true;
}

bool validate(vector<vector<int>>& sudoku) {
	if (validateRow(sudoku) && validateColumn(sudoku) && validateSubgrid(sudoku))
		return true;
	return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<vector<int>> sudoku(10, vector<int>(10, 0));

		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cin >> sudoku[i][j];
			}
		}

		int ans = validate(sudoku);
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}
