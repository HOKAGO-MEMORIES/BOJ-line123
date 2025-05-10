#include <iostream>
#include <vector>
using namespace std;

void printSpin(int n, vector<vector<int>>& matrix) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			cout << matrix[j][i];
		}

		cout << " ";

		for (int j = n - 1; j >= 0; j--) {
			cout << matrix[n - i - 1][j];
		}

		cout << " ";

		for (int j = 0; j < n; j++) {
			cout << matrix[j][n - i - 1];
		}

		cout << '\n';
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
		
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}

		cout << "#" << test_case << '\n';
		printSpin(n, matrix);
	}
	return 0;
}
